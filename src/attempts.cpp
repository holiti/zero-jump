#include "attempts.h"

Attempt::Attempt():
    ctime(nullptr),score(0)
{
}

Attempt::Attempt(int ascore):
    score(ascore)
{
    time_t cur; 
    time(&cur);
    ctime = localtime(&cur); 
}

void Attempt::swap(Attempt &b){
    tm* buff = ctime;
    ctime = b.ctime;
    b.ctime = buff;

    int buff1 = score;
    score = b.score;
    b.score = buff1;
}

char* Attempt::toString() const{
    char* buff = new char[TIME_BUFF]; 
    strftime(buff, TIME_BUFF, TIME_FORM, ctime);
    return buff;
}

bool Attempt::operator< (const Attempt& b) const{
    return score < b.score;
}

Attempt::~Attempt(){
    delete ctime;
}

AttManager::AttManager(){
    filename = "../data/attempts.bin";
    std::ifstream in(filename, std::ios::binary);

    in.read(reinterpret_cast<char*> (&size), sizeof(short));
    in.read(reinterpret_cast<char*> (atp), ATTEMPTS_N * sizeof(AttManager));

    in.close();
}

void AttManager::addAtt(int score){
    Attempt cur(score);

    int x; 
    for(x = 0;x < size;++x){
        if(cur < atp[x]){
            break;
        }
    }

    if(x == ATTEMPTS_N)
        return;
    ++size;

    cur.swap(atp[x]);
    for(x = x + 1;x < size;++x)
        cur.swap(atp[x]);
}

char* AttManager::getAtt(int index) const{
    return atp[index].toString();
}

AttManager::~AttManager(){
    std::ofstream out(filename, std::ios::binary);

    out.write(reinterpret_cast<char*>(&size), sizeof(short));
    out.write(reinterpret_cast<char*>(atp), ATTEMPTS_N * sizeof(Attempt));

    out.close();
    delete filename;
}




