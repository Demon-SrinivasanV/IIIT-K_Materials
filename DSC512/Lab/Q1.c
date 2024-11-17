/*
** A war game is conducted between two countries A and B.
** Country A at its Air Force Base in Rimnicu Vilcea has some Rockwell B-1 Lancer Heavy Bombers and
** some Mitsubishi F-3 Fighters. Since bombers are comparatively slow and are not easily maneuverable
** each bomber should be accompanied by at least a squadron of three fighters.
** Rimnicu Vilcea Air Force Base has over 5000 liter of fuel, 200 pilots, 4 wing commanders and an Air Marshal.
** Moreover, enemy airfields of Sibiu and Fagaras are within reach of the bombers from Rimnicu Vilcea.
** So, airfields of Rimnicu Vilcea should remain operational, it is vital for winning the war.
** According to Air Marshal Prince Constantin Cantacuzino, “We need at least 10 fighters in the air
** to defend against their first wave of attack”. Assume that both Rockwell B-1 Lancer Heavy Bomber and
** Mitsubishi F-3 Fighter can be operated by a single pilot. Assume that all the pilots, wing commanders and
** Air Marshal are competent pilots but due to tactical reasons Air Marshals are not allowed to participate in any flying missions.
** 
** Can you write a C program to read the number of fighters and bombers from the user and identify the maximum
** numbers Rockwell B-1 Heavy Bombers that can be sent on a bombing run at a 
** time by country A so that airfields of Rimnicu Vilcea won’t be vulnerable to air raids from Country B’s bombers?
** 
** Assume each plane (bomber or fighter) can be operated by a single Pilot.
** You have to input the number of fighter first followed by the number of bombers.
** 
** 
** Sample Input/Output
**     Input:
**     > 0 0
**     Output
**     > 0
*/


#include<stdio.h>

void main()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    a-=10;
    if(a<=0 || b<=0)
    {
        printf("0");
    }
    else
    {
        int c = b;
        c = a/3;
        if(c>b)
        {
            if(b>48)
                printf("48");
            else
                printf("%d", b);
        }
        else
        {
            if(c>48)
                printf("48");
            else
                printf("%d", c);
        }
        
    }
}