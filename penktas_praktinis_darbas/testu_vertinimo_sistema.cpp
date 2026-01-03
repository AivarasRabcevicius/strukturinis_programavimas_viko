#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

struct Student
{
    int id;
    char ats[20];
    double taskai = 0;
    int balas;
    int procentas;
};

int klausimai_teisingai[20] = {0};
int klausimai_neteisingai[20] = {0};
int klausimai_neatsakyta[20] = {0};

char teisingi[20];
int choice_main;
bool quit = false;
bool klausimo_statistika_done = false;

vector<Student> student_list;

void klases_statistika()
{
    int studentu_skaicius = student_list.size() - 1;
    cout << "studentu skaicius: " << studentu_skaicius << endl;
    int maziausias_balas = 10;
    int didziausias_balas = 1;
    double vid_balas;
    double vid_procentas;
    double balu_suma = 0;
    double procentu_suma = 0;
    int pazymiai[11] = {0};
    for (int i = 0; i < studentu_skaicius; i++)
    {
        if (student_list[i].balas < maziausias_balas)
        {
            maziausias_balas = student_list[i].balas;
        }
        if (student_list[i].balas > didziausias_balas)
        {
            didziausias_balas = student_list[i].balas;
        }
        balu_suma += student_list[i].balas;
        procentu_suma += student_list[i].procentas;
        pazymiai[student_list[i].balas]++;
    }
    cout << "Maziausias balas: " << maziausias_balas << endl;
    cout << "Didziausias balas: " << didziausias_balas << endl;
    vid_balas = balu_suma / studentu_skaicius;
    vid_procentas = procentu_suma / studentu_skaicius;
    cout << "Vidutinis balas: " << fixed << setprecision(2) << vid_balas << endl;
    cout << "Vidutinis procentas: " << fixed << setprecision(2) << vid_procentas << "%" << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << "Pazymi " << i << " gavo: " << pazymiai[i] << " studentai" << endl;
    }
}

void studento_paieska()
{
    cout << "Iveskite studento ID: ";
    while (true)
    {

        int ieskomas_id;
        bool rastas = false;
        cin >> ieskomas_id;
        for (int i = 0; i < student_list.size() - 1; i++)
        {
            if (student_list[i].id == ieskomas_id)
            {
                rastas = true;
                break;
            }
        }
        if (ieskomas_id == 0)
        {
            break;
        }
        if (rastas == false)
        {
            cout << "Studentas su ID " << ieskomas_id << " nerastas, bandykite dar karta:" << endl;
        }
        if (rastas == true)
        {
            cout << "studento atsakymai: ";
            for (int i = 0; i < 20; i++)
            {
                cout << student_list[ieskomas_id - 1].ats[i] << " ";
            }
            cout << endl
                 << "kito studento paieska (0 kad iseiti): ";
            cout << endl;
        }
    }
}

void issaugojimas()
{
    ofstream myfile;
    myfile.open("rezultatai.txt");
    if (myfile.is_open())
    {
        cout << "Failas atidarytas sekmingai" << endl;
    }
    else
    {
        cout << "Failo atidaryti nepavyko" << endl;
    }
    for (int i = 0; i < student_list.size() - 1; i++)
    {
        myfile << "studento id: " << student_list[i].id << " studento taskai: " << student_list[i].taskai << " studento balas: " << student_list[i].balas << " studento procentas: " << student_list[i].procentas << endl;
    }
    myfile.close();
}

void klausimo_statistika(bool showResults = true)
{
    if (!klausimo_statistika_done)
    {
        for (int i = 0; i < student_list.size() - 1; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (student_list[i].ats[j] == teisingi[j])
                {
                    klausimai_teisingai[j]++;
                }
                else if (student_list[i].ats[j] == '-')
                {
                    klausimai_neatsakyta[j]++;
                }
                else
                {
                    klausimai_neteisingai[j]++;
                }
            }
        }
        klausimo_statistika_done = true;
    }
    if (showResults)
    {
        for (int i = 0; i < 20; i++)
        {
            cout << "Klausimas " << i + 1 << ": Teisingai atsake: " << klausimai_teisingai[i] << ", Neteisingai atsake: " << klausimai_neteisingai[i] << ", Neatsake: " << klausimai_neatsakyta[i] << endl;
        }
    }
}

void sunkiausias_klausimas()
{
    klausimo_statistika(false);
    int maziausiai_teisingu = student_list.size() - 1;
    for (int i = 0; i < 20; i++)
    {
        if (klausimai_teisingai[i] < maziausiai_teisingu)
        {
            maziausiai_teisingu = klausimai_teisingai[i];
        }
    }
    cout << "Maziausiai teisingu atsakymu: " << maziausiai_teisingu << endl;
    cout << "Sunkiausias klausimas(-ai): ";
    for (int i = 0; i < 20; i++)
    {
        if (klausimai_teisingai[i] == maziausiai_teisingu)
        {
            cout << i + 1 << ", ";
        }
    }
    cout << endl;
}

int main()
{

    fstream myfile;
    myfile.open("testData.txt");
    if (myfile.is_open())
    {
        cout << "Failas atidarytas sekmingai" << endl;
    }
    else
    {
        cout << "Failo atidaryti nepavyko" << endl;
    }

    for (int i = 0; i < 20; i++)
    {
        myfile >> teisingi[i];
        cout << teisingi[i];
    }
    cout << endl;
    while (!myfile.eof())
    {
        Student stud;
        myfile >> stud.id;
        for (int i = 0; i < 20; i++)
        {
            myfile >> stud.ats[i];
            if (stud.ats[i] == teisingi[i])
            {
                stud.taskai += 2;
            }
            else if (stud.ats[i] == '-')
            {
                ;
            }
            else
            {
                stud.taskai -= 1;
            }
        }
        stud.balas = round(stud.taskai / 4);
        if (stud.balas < 1)
            stud.balas = 1;
        stud.procentas = round((stud.taskai / 40.0) * 100);
        cout << "studento id" << stud.id << " studento taskai: " << stud.taskai << " studento balas: " << stud.balas << " studento procentas: " << stud.procentas << endl;
        student_list.push_back(stud);
    }
    cout << student_list.size() << endl;
    for (int i = 0; i < student_list.size() - 1; i++)
    {

        cout << student_list[i].id;
        for (int j = 0; j < 20; j++)
        {
            cout << student_list[i].ats[j];
        }
        cout << endl;
    }
    myfile.close();

    while (quit == false)
    {
        cout << "Pasirinkite veiksma: " << endl;
        cout << "1. Klases statistika" << endl;
        cout << "2. Studento paieska" << endl;
        cout << "3. Issaugojimas i faila" << endl;
        cout << "4. Statistika pagal klausimus" << endl;
        cout << "5. Sunkiausias klausimas" << endl;
        cout << "6. Baigti darba" << endl;
        cin >> choice_main;
        switch (choice_main)
        {
        case 1:
            klases_statistika();
            break;
        case 2:
            studento_paieska();
            break;
        case 3:
            issaugojimas();
            break;
        case 4:
            klausimo_statistika();
            break;
        case 5:
            sunkiausias_klausimas();
            break;
        case 6:
            quit = true;
            break;
        default:
            cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        }
    }
}