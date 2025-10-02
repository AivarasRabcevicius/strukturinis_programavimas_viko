#include <iostream>
using namespace std;
int main() {
    bool break_cmd = false;
    string valiuta_str_1 , valiuta_str_2;
    int pasirinkimas_main , pasirnikimas_valiuta1 , pasirnikimas_valiuta2 , pasirinikimas_pirkti , pasirinkimas_parduoti;
    double eur=1000 , gbp=0 , usd = 0 , inr = 0 , eur_bendras = 1 , gbp_bendras = 0.8729 , usd_bendras = 1.1793 , inr_bendras = 104.6918;
    double valiuta_kursas_1 , valiuta_kursas_2;
    double pasirinktas_kiekis , perkama_valiuta , parduodama_valiuta , pasirinkta_valiuta_kursas;
    double gbp_pirkti = 0.8600 , gbp_parduoti = 0.9220 , usd_pirkti = 1.1460 , usd_parduoti = 1.2340 , inr_pirkti = 101.3862 , inr_parduoti = 107.8546;
    while (true) {
        cout << "jus turite: " << eur << " euru ," << gbp << " poundu, " << usd << " doleriu, " << inr << " rupiju." <<endl;
        cout << "pasirinkite operacija:" << endl;
        cout <<"spausti 1: kurso palyginimas" << endl;
        cout <<"spausti 2: isigyti valiutos uz eurus" << endl;
        cout <<"spausti 3: keisti valiuta i eurus" << endl;
        cout << "spausti 4: iseiti" <<endl;

        cin >> pasirinkimas_main;
        switch (pasirinkimas_main) {
            case 1: {
                cout << "pasirinkite pirma valiuta :" << endl;
                cout <<"spausti 1: EUR" << endl;
                cout <<"spausti 2: GBP" << endl;
                cout <<"spausti 3: USD" << endl;
                cout <<"spausti 4: INR" << endl;
                cin >> pasirnikimas_valiuta1;
                switch (pasirnikimas_valiuta1) {
                    case 1:
                        valiuta_str_1="euras";
                        valiuta_kursas_1 = eur_bendras;
                        break;
                    case 2:
                        valiuta_str_1="didziosio britanijos poundas";
                        valiuta_kursas_1 = gbp_bendras;
                        break;
                    case 3:
                        valiuta_str_1="jungtiniu valstiju doleris";
                        valiuta_kursas_1 = usd_bendras;
                        break;
                    case 4:
                        valiuta_str_1="indijos rupijas";
                        valiuta_kursas_1 = inr_bendras;
                        break;
                }
                cout << "pasirinkite antra valiuta :" << endl;
                cout <<"spausti 1: EUR" << endl;
                cout <<"spausti 2: GBP" << endl;
                cout <<"spausti 3: USD" << endl;
                cout <<"spausti 4: INR" << endl;
                cin >> pasirnikimas_valiuta2;
                switch (pasirnikimas_valiuta2) {
                    case 1:
                        valiuta_str_2="euro";
                        valiuta_kursas_2 = eur_bendras;
                        break;
                    case 2:
                        valiuta_str_2="didziosio britanijos poundo";
                        valiuta_kursas_2 = gbp_bendras;
                        break;
                    case 3:
                        valiuta_str_2="jungtiniu valstiju dolerio";
                        valiuta_kursas_2 = usd_bendras;
                        break;
                    case 4:
                        valiuta_str_2="indijos rupijo";
                        valiuta_kursas_2 = inr_bendras;
                        break;
                }
                cout << "vienas " << valiuta_str_1 << " lygus " << valiuta_kursas_2/valiuta_kursas_1 << " " << valiuta_str_2 << endl;
                break;
            }
            case 2: {
                cout<< "pasirinkite norima valiuta" << endl;
                cout <<"spausti 1: GBP" << endl;
                cout <<"spausti 2: USD" << endl;
                cout <<"spausti 3: INR" << endl;
                cin >> pasirinikimas_pirkti;
                switch (pasirinikimas_pirkti) {
                    case 1:
                        valiuta_str_1="didziosio britanijos poundo";
                        pasirinkta_valiuta_kursas = gbp_pirkti;
                        perkama_valiuta = gbp;
                        break;
                    case 2:
                        valiuta_str_1 = "jungtiniu valstiju dolerio";
                        pasirinkta_valiuta_kursas = usd_pirkti;
                        perkama_valiuta = usd;
                        break;
                    case 3:
                        valiuta_str_1 = "indijos rupijo";
                        pasirinkta_valiuta_kursas = inr_pirkti;
                        perkama_valiuta = inr;
                        break;
                }
                cout << "pirkimo kursas yra: " <<  pasirinkta_valiuta_kursas << " iveskite suma eur:" <<endl;
                cin>> pasirinktas_kiekis;
                perkama_valiuta = perkama_valiuta + pasirinktas_kiekis*pasirinkta_valiuta_kursas;
                eur = eur - pasirinktas_kiekis;
                cout << "jus nusipirkote " << pasirinktas_kiekis*pasirinkta_valiuta_kursas << " " << valiuta_str_1 << endl;
                switch (pasirinikimas_pirkti) {
                    case 1:
                        gbp = perkama_valiuta;
                        break;
                    case 2:
                        usd = perkama_valiuta;
                        break;
                    case 3:
                        inr = perkama_valiuta;
                        break;
                }
                break;
            }
            case 3: {
                cout<< "pasirinkite norima valiuta" << endl;
                cout <<"spausti 1: GBP" << endl;
                cout <<"spausti 2: USD" << endl;
                cout <<"spausti 3: INR" << endl;
                cin >> pasirinkimas_parduoti;
                switch (pasirinkimas_parduoti) {
                    case 1:
                        valiuta_str_1="didziosio britanijos poundo";
                        pasirinkta_valiuta_kursas = gbp_parduoti;
                        parduodama_valiuta = gbp;
                        break;
                    case 2:
                        valiuta_str_1 = "jungtiniu valstiju dolerio";
                        pasirinkta_valiuta_kursas = usd_parduoti;
                        parduodama_valiuta = usd;
                        break;
                    case 3:
                        valiuta_str_1 = "indijos rupijo";
                        pasirinkta_valiuta_kursas = inr_parduoti;
                        parduodama_valiuta = inr;
                        break;
                }
                cout << "pardavimo kursas yra: " <<  pasirinkta_valiuta_kursas << ", iveskite kiek norite parduoti " << valiuta_str_1 << ":" <<endl;
                cin>> pasirinktas_kiekis;
                parduodama_valiuta = parduodama_valiuta - pasirinktas_kiekis;
                eur = eur + pasirinktas_kiekis/pasirinkta_valiuta_kursas;
                cout << "jus gavote " << pasirinktas_kiekis/pasirinkta_valiuta_kursas << " " << valiuta_str_1 << endl;
                switch (pasirinkimas_parduoti) {
                    case 1:
                        gbp = parduodama_valiuta;
                        break;
                    case 2:
                        usd = parduodama_valiuta;
                        break;
                    case 3:
                        inr = parduodama_valiuta;
                        break;
                }
                break;
            }
            case 4: {
                break_cmd = true;
                break;
            }
        }
        if (break_cmd) break;
    }
    return 0;
}