class stack
{
    auto empty(s)
    {
        if (s.top == 0)
            return true;
        else return false;
    }

    auto push(s, x)
    {
        s.top = s.top + 1;
        s[s.top] = x;
    }
}
