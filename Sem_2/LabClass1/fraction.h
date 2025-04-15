#define fraction_h

struct aripr {
    double first;
    unsigned second; 

    void init(double a0, unsigned r);
    
    void read();
    
    void show() const;
    
    double element(int j) const;
};

aripr make_arithmetic_progression(double a0, unsigned r);

#endif