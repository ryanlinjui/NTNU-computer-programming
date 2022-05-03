#pragma once 
#include "lib/cstd.h"

#define Welcome_MSG \
"Welcome to PM2 modifier\n" \
"Please input your filename\n"

#define TOPIC_MSG \
"Select a topic:\n" \
"(1) Attribute\n" \
"(2) Ability\n" \
"(3) Reputation\n" \
"(4) Performance\n" \
"(0) Exit program\n"

#define ATTRIBUTE_MSG \
"Select a arrribute you want to modify:\n" \
"(1) stamina\n" \
"(2) strnth\n" \
"(3) intell\n" \
"(4) elegance\n" \
"(5) glamour\n" \
"(6) morality\n" \
"(7) faith\n" \
"(8) karma\n" \
"(9) senstv\n" \
"(10) stress\n" \
"(0) Previous\n"

#define ABILITY_MSG \
"Select a ablity you want to modify:\n" \
"(1) fgt_skl\n" \
"(2) attack\n" \
"(3) defense\n" \
"(4) mag_skl\n" \
"(5) mag_atk\n" \
"(6) mag_def\n" \
"(0) Previous\n"

#define REPUTATION_MSG \
"Select a reputation you want to modify:\n" \
"(1) fgt_rep\n" \
"(2) mag_rep\n" \
"(3) scl_rep\n" \
"(4) hkp_rep\n" \
"(0) Previous\n"

#define PERFORMANCE_MSG \
"Select a performance you want to modify:\n" \
"(1) fgt_skl\n" \
"(2) attack\n" \
"(3) defense\n" \
"(4) mag_skl\n" \
"(5) mag_atk\n" \
"(6) mag_def\n" \
"(0) Previous\n"

struct 
{
    uint16_t stamina;
    uint16_t strnth;
    uint16_t intell;
    uint16_t elegance;
    uint16_t glamour;
    uint16_t morality;
    uint16_t faith;
    uint16_t karma;
    uint16_t senstv;
    uint16_t stress;
}Attribute; //size: 20 Bytes

struct
{
    uint16_t fgt_skl;
    uint16_t attack;
    uint16_t defense;
    uint16_t mag_skl;
    uint16_t mag_atk;
    uint16_t mag_def; 
}Ability; //size: 12 Bytes

struct
{
    uint16_t fgt_rep;
    uint16_t mag_rep;
    uint16_t scl_rep;
    uint16_t hkp_rep;
}Reputation; //size: 8 Bytes

struct
{
    uint16_t decorum;
    uint16_t art_skl;
    uint16_t speech;
    uint16_t cooking;
    uint16_t cln_ldr;
    uint16_t personal;
}Performance; //size: 12 Bytes

#define ATTRIBUTE_OFFSET 62
#define ABILITY_OFFSET 82
#define REPUTATION_OFFSET 94 
#define PERFORMANCE_OFFSET 102

void set_modifier(char *filename)
{
    int32_t fd = open( filename, O_RDWR );
    CHECK_VALID(fd==-1,"Open file error!!");
    
    char *file = NULL;

    // get fd size start
    struct stat statbuf; 
    if( fstat( fd, &statbuf ) < 0 )
    {
        close( fd );
        puts("fd error!!");
        exit(0);
    } 
    uint64_t file_size =  statbuf.st_size; 
    // get fd size end

    file = mmap( 0, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );
    
    memcpy(&Attribute,file+ATTRIBUTE_OFFSET,sizeof(Attribute));
    memcpy(&Ability,file+ABILITY_OFFSET,sizeof(Ability));
    memcpy(&Reputation,file+REPUTATION_OFFSET,sizeof(Reputation));
    memcpy(&Performance,file+PERFORMANCE_OFFSET,sizeof(Performance));

    munmap(file,file_size);
    close(fd);
}

void topic_menu(int32_t choice, uint8_t *func_num)
{
    system("clear");
    puts(TOPIC_MSG);
    CHECK_VALID(scanf("%d", &choice)==1 && choice>=0 && choice<=4,"Value must be one and in range 0 to 4!!");
    if(choice==0) exit(0);
    *func_num = (uint8_t)choice;
}

void attribute_menu(int32_t choice, uint8_t *func_num)
{
    system("clear");
    puts(ATTRIBUTE_MSG);
    CHECK_VALID(scanf("%d", &choice)==1 && choice>=0 && choice<=10,"Value must be one and in range 0 to 10!!");
    if(choice==0)
    {
        *func_num = 0;
    }
    else
    {
        *func_num = 1;
    }
}

void ablity_menu(int32_t choice, uint8_t *func_num)
{
    system("clear");
    puts(ABILITY_MSG);
    CHECK_VALID(scanf("%d", &choice)==1 && choice>=0 && choice<=6,"Value must be one and in range 0 to 6!!");
    if(choice==0)
    {
        *func_num = 0;
    }
    else
    {
        *func_num = 1;
    }
}

void reputation_menu(int32_t choice, uint8_t *func_num)
{
    system("clear");
    puts(REPUTATION_MSG);
    CHECK_VALID(scanf("%d", &choice)==1 && choice>=0 && choice<=4,"Value must be one and in range 0 to 4!!");
    if(choice==0)
    {
        *func_num = 0;
    }
    else
    {
        *func_num = 1;
    }
}

void performance_menu(int32_t choice, uint8_t *func_num)
{
    system("clear");
    puts(PERFORMANCE_MSG);
    CHECK_VALID(scanf("%d", &choice)==1 && choice>=0 && choice<=6,"Value must be one and in range 0 to 6!!");
    if(choice==0)
    {
        *func_num = 0;
    }
    else
    {
        *func_num = 1;
    }
}
void (*func_arr[5])(int32_t,uint8_t*) = {topic_menu,attribute_menu,ablity_menu,reputation_menu,performance_menu};