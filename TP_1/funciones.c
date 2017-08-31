float suma(float x, float y)
{
    float resultado;
    resultado= x+y;
    return resultado;
}

float resta (int x, int y)
{
    float resultado;
    resultado= x-y;
    return resultado;
}

float division(int x, int y)
{
    float resultado;
    resultado= x/y;
    return resultado;
}

float multiplicacion(int x, int y)
{
    float resultado;
    resultado= x*y;
    return resultado;
}

float factorial(int x)
{
    float resultado;
    if(x==1)
        return 1;
    resultado=x*factorial(x-1);
    return resultado;
}

float getFloat(char mensaje[])
{
    float x;
    printf("%s", mensaje);
    scanf("%f", &x);
    return x;
}

int verificaCero(float x)
{
    if (x != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
