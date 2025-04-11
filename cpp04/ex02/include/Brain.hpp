#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
   public:
    // constructors
    Brain();
    Brain(const Brain& copy);

    // assignment operator
    Brain& operator=(const Brain& copy);

    // destructor
    ~Brain();

    // member functions
    std::string getIdea(int index) const;
    void setIdea(int index, std::string idea);

   private:
    static const int MAX_IDEAS = 100;

   protected:
    std::string _ideas[MAX_IDEAS];
};

#endif