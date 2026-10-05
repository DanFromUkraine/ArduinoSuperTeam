int choice = 0;
int aNum = 0;
int bNum = 0;

enum State
{
    WAIT_CHOICE,
    WAIT_A,
    WAIT_B
};

State state = WAIT_CHOICE;

void showMenu()
{
    Serial.println();
    Serial.println("1 = Sum");
    Serial.println("2 = Multiplication");
    Serial.print("Choose operation: ");
}

void setup()
{
    Serial.begin(9600);
    delay(50);

    showMenu();
}

void loop()
{
    if (Serial.available() <= 0)
        return;

    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.length() == 0)
        return;

    int inp = input.toInt();

    switch (state)
    {
        case WAIT_CHOICE:
            if (inp == 1 || inp == 2)
            {
                choice = inp;

                Serial.print("Enter number A: ");
                state = WAIT_A;
            }
            else
            {
                Serial.println("Invalid choice. Enter 1 or 2:");
            }
            break;

        case WAIT_A:
            aNum = inp;

            Serial.print("Enter number B: ");
            state = WAIT_B;
            break;

        case WAIT_B:
            bNum = inp;

            int result;

            if (choice == 1)
                result = aNum + bNum;
            else
                result = aNum * bNum;

            Serial.print("Result: ");
            Serial.println(result);

            state = WAIT_CHOICE;
            showMenu();
            break;
    }
}