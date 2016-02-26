class Temp
{
public:
    Temp() { ++n; sum += n; }

    static void Reset() { n = 0; sum = 0; }
    static unsigned int GetSum() { return sum; }

private:
    static unsigned int n;
    static unsigned int sum;
};

unsigned int Temp::n = 0;
unsigned int Temp::sum = 0;

unsigned int Sum_Solutionl(unsigned int n)
{
    Temp::Reset();

    Temp *a = new Temp[n];
    delete []a;
    a = nullptr;

    return Temp::GetSum();
}
