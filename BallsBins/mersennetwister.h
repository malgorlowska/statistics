#ifndef MERSENNETWISTER_H
#define MERSENNETWISTER_H


class mersenneTwister
{
private:
    unsigned int MT [ 624 ];
    int mti = 0;
public:
    mersenneTwister();
    void initMT ( unsigned int);
    void initializationMT( );
    unsigned int MersenneTwister();
};

#endif // MERSENNETWISTER_H
