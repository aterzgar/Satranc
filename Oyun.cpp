// Arda Mavi - ardamavi.com

#include <iostream>
#include <utility>
#include "Color.h" // namespace Color
#include "Tahta.h"
#include "Tas.h"
#include "Piyon.h"
#include "At.h"
#include "Fil.h"
#include "Sah.h"
#include "Kale.h"
#include "Vezir.h"
#include "Color.h"

Color::Modifier defaultColorfg(Color::FG_DEFAULT);
Color::Modifier defaultColorbg(Color::BG_DEFAULT);

using namespace std;

int harfToSayi(char harf){
  return ((int)(harf)-97);
}

int sayiCharToSayi(char sayiChar){
  return ((int)sayiChar-49);
}

int main(){

    // Mac icin ekran temizleme:

    system("clear");

    // Mac için seslendirme:
    //system("say Arda Mavi nin Satranç oyununa hoş geldiniz");

    cout << defaultColorbg << defaultColorfg;

    cout << "- Satranç -\nArda Mavi - ardamavi.com" << endl;
    cout << "Girişler SayiHarf seklinde olmalidir. Orn: 2e" << endl;
    cout << "Oyundan çıkış: kntrl c\n" << endl;

    string kazanan = "Yok";
    string oyunSirasi = "Siyah";
    pair <int, int> tasinKonumu;
    pair <int, int> oynanacakYer;
    bool sahDurum = false;

    Tahta tahta;

  do{

    // Siradaki Oyuncu Dondurulur.
    if(oyunSirasi == "Beyaz"){
        oyunSirasi = "Siyah";
    }else{
        oyunSirasi = "Beyaz";
    }

    bool oynamaTamamMi = true;

    do{

      cout << defaultColorbg << defaultColorfg << endl;
      // Tahta Silinir ve Cizilir:
      tahta.tahtaCiz();
      cout << defaultColorbg << defaultColorfg << endl;

      if(!oynamaTamamMi){
        cout << "\nHatalı Giriş !\n";
        system("say Hatalı giriş!");
      }

    // Mac icin oyun sırası seslendirme:
    cout << "\nOyun Sırası: " << oyunSirasi << endl;
    if(oyunSirasi == "Beyaz"){
      system("say Oyun sırası beyaz takımda");
    }else if(oyunSirasi == "Siyah"){
      system("say Oyun sırası siyah takımda");
    }

    char tasinKonumuChar[3];
    cout << "\nTaşın Konumunu giriniz: ";
    cin >> tasinKonumuChar;
    tasinKonumu.first = sayiCharToSayi(tasinKonumuChar[0]);
    tasinKonumu.second = harfToSayi(tasinKonumuChar[1]);

    char oynanacakYerChar[3];
    cout << "\nTaşı Oynayacağınız Konumu Giriniz: ";
    cin >> oynanacakYerChar;
    oynanacakYer.first = sayiCharToSayi(oynanacakYerChar[0]);
    oynanacakYer.second = harfToSayi(oynanacakYerChar[1]);

    if(sahDurum == true){

      string eskiOyunSirasi;

      if(oyunSirasi == "Beyaz"){
        eskiOyunSirasi = "Siyah";
      }else if(oyunSirasi == "Siyah"){
        eskiOyunSirasi = "Beyaz";
      }

      vector<Tas*> taslarKopya;

      // Taşlar kopyalanır:
      for (int i = 0; i < tahta.getTaslar()->size(); i++) {
        taslarKopya.push_back(new Tas(*(*(tahta.getTaslar()))[i]));
      }

      tahta.hareketEt(oyunSirasi, tasinKonumu, oynanacakYer);

      sahDurum = tahta.sahVarMi(eskiOyunSirasi);

      if(sahDurum == true){
        // Kopyalanan orijinale atanir :
        tahta.setTaslar(taslarKopya);
        cout << "Şahınızı kurtarmanız lazım !" << endl;

        // Mac için seslendirme :
        system("say Şahınızı kurtarmanız lazım !");

        oynamaTamamMi = false;
      }else{
        //Dogru oynanmis mi :
        oynamaTamamMi = true;
      }

    }else{
      //Dogru oynanmis mi :
      oynamaTamamMi = (tahta.hareketEt(oyunSirasi, tasinKonumu,oynanacakYer));

    }

    // Mac icin ekran temizleme:
    system("clear");

  }while(!oynamaTamamMi);

    sahDurum = tahta.sahVarMi(oyunSirasi);

    // Sah mı ?
    if(sahDurum){
      cout << "Şah !" << endl;

      // Mac için seslendirme :
      system("say Şah !");
    }

  }while(kazanan == "Yok");

  // Tahta Silinir ve Cizilir:
  tahta.tahtaCiz();

  cout << "\nKazanan: " << kazanan << "\nOyun Bitti\n" << endl;

  // Mac icin oyunun bitimini sesli haber verme:
  system("say Oyun bitti !");
  system("say Kazanan: ");

  // Mac icin kazanan seslendirme:
  if(kazanan == "Beyaz"){
    system("say Kazanan Beyaz takım!");
  }else if(kazanan == "Siyah"){
    system("say Kazanan Siyah takım!");
  }else{
    system("say Kazanan yok!");
  }

    return 0;
}
