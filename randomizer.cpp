#include<iostream>
#include<ctime>
#include<cstdlib>

class Randomizer{
  public:
    static Randomizer *instance();
    unsigned int randomBetween(unsigned int minimum, unsigned int maximum);
  private:
    static Randomizer *m_instance;
    bool isSeeded = false;
};

Randomizer *Randomizer::m_instance = NULL;

Randomizer *Randomizer::instance(){
  if(m_instance == NULL)
    m_instance = new Randomizer();
  return m_instance;
}

unsigned int Randomizer::randomBetween(unsigned int minimum, unsigned int maximum){
  if(isSeeded == false)
  {
    srand(time(NULL));
    isSeeded = true;
  }
  return rand()%(maximum-minimum + 1) + minimum;
}
