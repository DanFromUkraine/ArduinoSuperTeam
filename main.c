int choice = 0;
int aNum = 0;
int bNum = 0;

bool hasChoice = false;
bool hasA = false;
bool hasB = false;

void resetAll();
void Blink();

void setup()
{
    Serial.begin(9600);
    delay(50);
    Serial.println("1 = Sum");
    Serial.println("2 = Multiplication");
}

void loop()
{
    Blink();
}

void resetAll()
{
    hasChoice = false;
    hasA = false;
    hasB = false;
}

void Blink()
{
    if (Serial.available() > 0)
    {
        int inp = Serial.parseInt();

        if (!hasChoice && (inp == 1 || inp == 2))
        {
            choice = inp;
            hasChoice = true;
        }
        else if (!hasA)
        {
            aNum = inp;
            hasA = true;
        }
        else if (!hasB)
        {
            bNum = inp;
            hasB = true;
        }
    }

    if (hasChoice && hasA && hasB)
    {
        int result;

        if (choice == 1)
        {
            result = aNum + bNum;
        }
        else
        {
            result = aNum * bNum;
        }

        Serial.print("Result: ");
        Serial.println(result);

        resetAll();
    }
}
