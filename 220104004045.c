#include <stdio.h>
#include <string.h>

typedef struct
{
    char opcode[8];
    char type;
    char process_format;

} Instruction;

typedef struct
{
    char operandA[8];
    char operandB[8];
} Registers;

typedef struct
{
    int PC;
    char IR[24];
    char memory[1000][8];
} Simulator;

void int_to_binary(int decimal, char *binary)
{
    int i;
    for (i = 7; i >= 0; i--)
    {
        binary[i] = (decimal & 1) + '0';
        decimal >>= 1;
    }
    binary[8] = '\0';
}

int binary_to_int(const char *binary)
{
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);
    int i = 0;

    for (i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

void fetch(Instruction *instruct, Simulator *simulator, Registers *registers)
{
    char line[100];
    int line_number = 0;

    FILE *file = fopen("instruction.txt", "r");

    if (file == NULL)
    {
        printf("File doesnt open\n");
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        strcpy(simulator->memory[line_number], line);
        line_number++;
    }

    strcpy(simulator->IR, simulator->memory[simulator->PC]);

    printf("%s\n", simulator->IR);

    fclose(file);

    return;
}

void decode_and_execute(Instruction *inst, Simulator *simulator, Registers *registers)
{
    FILE *file = fopen("instruction.txt", "r");

    if (file == NULL)
    {
        printf("File doesnt open\n");
    }

    fscanf(file, "%[^\t]s|%c|%s|%s\n", &instruct->oppcode, &inst->operandA, &inst->operandB)
    {

        printf("%c %s %s\n", inst->oppcode, inst->operandA, inst->operandB);
    }
}

int main()
{
    Instruction instruct;
    Simulator simulator;
    Registers registers;

    int flag = 1;
    int i = 0;
    char line[100];
    int line_number = 0;

    int a = 0;

    a >>= 1;

    printf("%d", a);

    while (flag)
    {
        fetch(&instruct);
        decode_and_execute(&instruct);
        simulator.PC++;
    }

    return 0;
}