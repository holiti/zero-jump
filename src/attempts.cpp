#include "attempts.h"

Attempt::Attempt():
    score(0)
{
}

Attempt::Attempt(int ascore):
    score(ascore)
{
    time_t cur; 
    time(&cur);
    ctime = *localtime(&cur); 
}

void Attempt::swap(Attempt &b){
    tm buff = ctime;
    ctime = b.ctime;
    b.ctime = buff;

    int buff1 = score;
    score = b.score;
    b.score = buff1;
}

std::string Attempt::toString() const{
    char* buff = new char[TIME_BUFF]; 
    strftime(buff, TIME_BUFF, TIME_FORM, &ctime);
    
    std::stringstream ss;
    ss << buff << " score: "; 

    for(int x = 1000000,cur = score;x > 0;x /= 10){
        ss << cur / x;
        cur = cur % x; 
    }

    delete[] buff;

    return ss.str();
}

bool Attempt::operator< (const Attempt& b) const{
    if(score != b.score)
        return score < b.score;

    time_t t1 = mktime(const_cast<tm*>(&ctime));
    time_t t2 = mktime(const_cast<tm*>(&b.ctime));

    return t1 < t2;
}

Attempt::~Attempt(){
}

AttManager::AttManager(){
    std::ifstream in("../data/attempts.bin", std::ios::binary);

    in.read(reinterpret_cast<char*> (&size), sizeof(short));
    in.read(reinterpret_cast<char*> (atp), size * sizeof(AttManager));

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

std::string AttManager::getAtt(int index) const{
    return atp[index].toString();
}

AttManager::~AttManager(){
    std::ofstream out("../data/attempts.bin", std::ios::binary);

    out.write(reinterpret_cast<char*>(&size), sizeof(short));
    out.write(reinterpret_cast<char*>(atp), size * sizeof(Attempt));

    out.close();
}




