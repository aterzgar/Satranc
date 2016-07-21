// Arda Mavi - ardamavi.com

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Tas.h"

using namespace std;

  string Tas::tasKisaltmasi(){

  string kisaltma = " ";

  if(this->renk == 1){
    // renk beyaz:

    // Unicode :
    switch (adi[0]) {
      case 'P':
      kisaltma += "\u265F";
      break;
      case 'K':
      kisaltma += "\u265C";
      break;
      case 'A':
      kisaltma += "\u265E";
      break;
      case 'F':
      kisaltma += "\u265D";
      break;
      case 'V':
      kisaltma += "\u265B";
      break;
      case 'S':
      kisaltma += "\u265A";
      break;
    }

  }else{
    // renk siyah:

    // Unicode :
    switch (adi[0]) {
      case 'P':
      kisaltma += "\u265F";
      break;
      case 'K':
      kisaltma += "\u265C";
      break;
      case 'A':
      kisaltma += "\u265E";
      break;
      case 'F':
      kisaltma += "\u265D";
      break;
      case 'V':
      kisaltma += "\u265B";
      break;
      case 'S':
      kisaltma += "\u265A";
      break;
    }

  }

  kisaltma += " ";

  return kisaltma;
}


Tas::Tas(takim renk, string adi, int x, int y){
    this->renk = renk;
    this->adi = adi;
    this->konum = make_pair(x, y);
}

pair<int, int> Tas::getKonum() {
    return this->konum;
}

takim  Tas::getTakim(){
    return this->renk;
}

string Tas::getAdi(){
    return this->adi;
}

void Tas::setKonum(pair <int, int> gidilecekYer){
    this->konum = gidilecekYer;
}
