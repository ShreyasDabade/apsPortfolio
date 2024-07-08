//this is the code which was developed for the dsa course project in 3rd sem by our team
//this code uses multiple algorithms to electrify the city and connect to multiple cities

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#define N 15 // inter house connections
#define MAX_WEIGHT 50
#define V 4 // inter city and inter colony connections
#define INF INT_MAX
#define C 15
#define ROWS 15
#define COLUMNS 15
#define ROWS1 15
#define COLUMNS1 15

struct home
{
    char name[20];
    int house_num;
    int units_consumed;
    int amount_per_unit;
};

int w1 = 0;
int sum1 = 0;
char c[4][20] = {"Source", "Hubli    ", "Dharwad", "Navalgund"};
FILE *fp;

/*this prims algorithm is named primMSTcolony because its calculates distance between the colonies and gives
  us the minimum spanning tree in this way we make connections in the city .Because there are 15 houses in each
  colony (C=15) but there are only 4 colonies*/

int main()
{
    fp = fopen("output.txt", "w");
    int i, j;
    int h0[N][N];
    int h1[N][N];
    int h2[N][N];
    int h3[N][N];
    struct home hA[N];
    struct home hB[N];
    struct home hC[N];
    struct home hD[N];
    int d0[N][N];
    int d1[N][N];
    int d2[N][N];
    int d3[N][N];
    struct home dA[N];
    struct home dB[N];
    struct home dC[N];
    struct home dD[N];
    int n0[N][N];
    int n1[N][N];
    int n2[N][N];
    int n3[N][N];
    struct home nA[N];
    struct home nB[N];
    struct home nC[N];
    struct home nD[N];

    int hubli[4][4];
    int navalgund[4][4];
    int dharwad[4][4];
    int powergrid_city_array[4][4];
    readFile("h0.txt", h0);
    readFile("h1.txt", h1);
    readFile("h2.txt", h2);
    readFile("h3.txt", h3);
    readFile("d0.txt", d0);
    readFile("d1.txt", d1);
    readFile("d2.txt", d2);
    readFile("d3.txt", d3);
    readFile("n0.txt", n0);
    readFile("n1.txt", n1);
    readFile("n2.txt", n2);
    readFile("n3.txt", n3);
    readFile_c("hubli.txt", hubli);
    readFile_c("navalgund.txt", navalgund);
    readFile_c("dharwad.txt", dharwad);
    readFile_c("citiess.txt", powergrid_city_array);

    int c1 = 0, c2 = 0, c3 = 0, y = 0;
    readStruct(hA, "hA.txt");
    readStruct(hB, "hB.txt");
    readStruct(hC, "hC.txt");
    readStruct(hD, "hD.txt");
    readStruct(dA, "dA.txt");
    readStruct(dB, "dB.txt");
    readStruct(dC, "dC.txt");
    readStruct(dD, "dD.txt");
    readStruct(nA, "nA.txt");
    readStruct(nB, "nB.txt");
    readStruct(nC, "nC.txt");
    readStruct(nD, "nD.txt");
    int x = 0;
    yellow();
    printf("Connections between Power Grid to all CITIES : \n\n");
    reset();
    fprintf(fp, "Connections between Power Grid to all CITIES : \n\n");
    sum1 = 0;
    primMST1(powergrid_city_array);
    printf("\n");
    fprintf(fp, "\n");
    printf("Total length of wire used for connecting all city : %d\n\n", sum1);
    fprintf(fp, "Total length of wire used for connecting all city : %d\n\n", sum1);
    c3 = sum1;
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Hubli City Colonies Interconnection :\n\n");
    reset();
    fprintf(fp, "Hubli City Colonies Interconnection :\n\n");
    green();
    printf("Colonies--distance\n");

    fprintf(fp, "Colonies--distance\n");
    printf("-------------------\n");
    reset();
    fprintf(fp, "-------------------\n");
    sum1 = 0;
    primMST(hubli);
    printf("\n");
    fprintf(fp, "\n");
    printf("Total length of wire used for connecting colonies in Hubli city : %d\n\n", sum1);
    fprintf(fp, "Total length of wire used for connecting colonies in Hubli city : %d\n\n", sum1);
    x = sum1 + x;
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Dharwad City Colonies Interconnection :\n\n");
    reset();
    fprintf(fp, "Dharwad City Colonies Interconnection :\n\n");
    green();
    printf("Colonies--distance\n");
    fprintf(fp, "Colonies--distance\n");
    printf("-------------------\n");
    reset();
    fprintf(fp, "-------------------\n");
    sum1 = 0;
    primMST(dharwad);
    printf("\n");
    fprintf(fp, "\n");
    printf("Total length of wire used for connecting colonies in Dharwad city : %d\n\n", sum1);
    fprintf(fp, "Total length of wire used for connecting colonies in Dharwad city : %d\n\n", sum1);
    x = sum1 + x;
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Navalgund City Colonies Interconnection :\n\n");
    reset();
    fprintf(fp, "Navalgund City Colonies Interconnection :\n\n");
    green();
    printf("Colonies--distance\n");
    fprintf(fp, "Colonies--distance\n");
    printf("-------------------\n");
    reset();
    fprintf(fp, "-------------------\n");
    sum1 = 0;
    primMST(navalgund);
    printf("\n");
    fprintf(fp, "\n");
    printf("Total length of wire used for connecting colonies in Navalgund city : %d\n\n", sum1);
    fprintf(fp, "Total length of wire used for connecting colonies in Navalgund city : %d\n\n", sum1);
    x = sum1 + x;
    printf("Total wire used in inter colonies for all three cities %d\n\n", x);
    fprintf(fp, "Total wire used in inter colonies for all three cities %d\n\n", x);
    sum1 = 0;
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("HUBLI CITY\n");

    fprintf(fp, "HUBLI CITY\n");
    printf("----------\n");
    reset();
    fprintf(fp, "----------\n");
    purple();
    printf("Colony 1 Interconnections:\n\n");
    reset();
    fprintf(fp, "Colony 1 Interconnections:\n\n");
    green();
    printf("Houses       distance\n");
    fprintf(fp, "Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "---------------------\n");
    primMSTcolony(h0);
    purple();
    printf("Colony 2 Interconnections:\n\n");
    reset();
    fprintf(fp, "Colony 2 Interconnections:\n\n");
    green();
    printf("Houses       distance\n");
    fprintf(fp, "Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "---------------------\n");
    primMSTcolony(h1);
    purple();
    printf("Colony 3 Interconnections:\n\n");
    reset();
    fprintf(fp, "Colony 3 Interconnections:\n\n");
    green();
    printf("Houses       distance\n");
    fprintf(fp, "Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "---------------------\n");
    primMSTcolony(h2);
    purple();
    printf("Colony 4 Interconnections:\n\n");
    reset();
    fprintf(fp, "Colony 4 Interconnections:\n\n");
    green();
    printf("Houses       distance\n");
    fprintf(fp, "Houses       distance\n");
    printf("---------------------\n");
    fprintf(fp, "---------------------\n");
    reset();
    primMSTcolony(h3);
    printf("Total length of wire used in Hubli city : %d\n\n", w1);
    fprintf(fp, "Total length of wire used in Hubli city : %d\n\n", w1);
    printf("Total cost for wiring in Hubli city :%d\n\n", (w1)*378);
    fprintf(fp, "Total cost for wiring in Hubli city :%d\n\n", (w1)*378);
    c1 = c1 + w1;
    w1 = 0;
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("DHARWAD CITY\n");

    fprintf(fp, "DHARWAD CITY\n");
    printf("------------\n");
     reset();
    fprintf(fp, "------------\n");
    purple();
    printf("Colony 1 Interconnections:\n\n");
    reset();
    green();
    printf("Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "Colony 1 Interconnections:\n\n");
    fprintf(fp, "Houses       distance\n");
    fprintf(fp, "---------------------\n");
    primMSTcolony(d0);
    purple();
    printf("Colony 2 Interconnections:\n\n");
    reset();
    green();
    printf("Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "Colony 2 Interconnections:\n\n");
    fprintf(fp, "Houses       distance\n");
    fprintf(fp, "---------------------\n");
    primMSTcolony(d1);
    purple();
    printf("Colony 3 Interconnections:\n\n");
    reset();
    green();
    printf("Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "Colony 3 Interconnections:\n\n");
    fprintf(fp, "Houses       distance\n");
    fprintf(fp, "---------------------\n");
    primMSTcolony(d2);
    purple();
    printf("Colony 4 Interconnections:\n\n");
    reset();
    green();
    printf("Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "Colony 4 Interconnections:\n\n");
    fprintf(fp, "Houses       distance\n");
    fprintf(fp, "---------------------\n");
    primMSTcolony(d3);
    printf("Total length of wire used in Dharwad city : %d\n\n", w1);
    printf("Total cost for wiring in Dharwad city :%d\n\n", (w1)*378);
    fprintf(fp, "Total length of wire used in Dharwad city : %d\n\n", w1);
    fprintf(fp, "Total cost for wiring in Dharwad city :%d\n\n", (w1)*378);
    c1 = c1 + w1;
    w1 = 0;
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("NAVALGUND CITY\n");

    printf("--------------\n");
     reset();
     purple();
    printf("Colony 1 Interconnections:\n\n");
    reset();
    green();
    printf("Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "NAVALGUND CITY\n");
    fprintf(fp, "--------------\n");
    fprintf(fp, "Colony 1 Interconnections:\n\n");
    fprintf(fp, "Houses       distance\n");
    fprintf(fp, "---------------------\n");
    primMSTcolony(n0);
    purple();
    printf("Colony 2 Interconnections:\n\n");
    reset();
    green();
    printf("Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "Colony 2 Interconnections:\n\n");
    fprintf(fp, "Houses       distance\n");
    fprintf(fp, "---------------------\n");
    primMSTcolony(n1);
    purple();
    printf("Colony 3 Interconnections:\n\n");
    reset();
    green();
    printf("Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "Colony 3 Interconnections:\n\n");
    fprintf(fp, "Houses       distance\n");
    fprintf(fp, "---------------------\n");
    primMSTcolony(n2);
    purple();
    printf("Colony 4 Interconnections:\n\n");
    reset();
    green();
    printf("Houses       distance\n");
    printf("---------------------\n");
    reset();
    fprintf(fp, "Colony 4 Interconnections:\n\n");
    fprintf(fp, "Houses       distance\n");
    fprintf(fp, "---------------------\n");
    primMSTcolony(n3);
    printf("Total length of wire used in navalgund city : %d\n\n", w1);

    printf("Total cost for wiring in navalgund city :%d\n", (w1)*378);
    fprintf(fp, "Total length of wire used in navalgund city : %d\n\n", w1);

    fprintf(fp, "Total cost for wiring in navalgund city :%d\n", (w1)*378);
    c1 = c1 + w1;
    w1 = 0;
    printf("\n\n");
    fprintf(fp, "\n\n");
    red();
    printf("Total length of wire used for interconnection of houses in  all three cities : %d\n\n", c1);
    fprintf(fp, "Total length of wire used for interconnection of houses in  all three cities : %d\n\n", c1);
    int z = 0;
    z = c1 * 378;
    y = y + z;
    printf("Total cost for wiring all houses in 3 cities : %d\n\n", z);
    fprintf(fp, "Total cost for wiring all houses in 3 cities : %d\n\n", z);
    z = x * 378;
    y = y + z;
    printf("Total cost for wiring all colonies in  cities :%d\n\n", z);
    fprintf(fp, "Total cost for wiring all colonies in  cities :%d\n\n", z);
    z = c3 * 576;
    y = y + z;

    printf("Total cost for wiring three cities: %d\n\n", z);
    printf("Total cost for wiring :%d\n\n", y);
    fprintf(fp, "Total cost for wiring three cities: %d\n\n", z);
    fprintf(fp, "Total cost for wiring :%d\n\n", y);

    sum1 = 0;
    // printf("Total wire used %d",c2);
    int summ[12];
    summ[0] = calculate_revenue_colonywise(hA);
    summ[1] = calculate_revenue_colonywise(hB);
    summ[2] = calculate_revenue_colonywise(hC);
    summ[3] = calculate_revenue_colonywise(hD);
    summ[4] = calculate_revenue_colonywise(nA);
    summ[5] = calculate_revenue_colonywise(nB);
    summ[6] = calculate_revenue_colonywise(nC);
    summ[7] = calculate_revenue_colonywise(nD);
    summ[8] = calculate_revenue_colonywise(dA);
    summ[9] = calculate_revenue_colonywise(dB);
    summ[10] = calculate_revenue_colonywise(dC);
    summ[11] = calculate_revenue_colonywise(dD);
    long long int TOTAL_REVENUE = 0;
    for (i = 0; i < 12; i++)
        TOTAL_REVENUE = TOTAL_REVENUE + summ[i];
    printf("Total revenue generated :%lld\n\n", TOTAL_REVENUE);
    reset();

    printf("Company will be profitable in %d years\n\n\n\n", (y / (TOTAL_REVENUE * 12)) + 1);
    yellow();
    printf("Shortest Path from PowerGrid to all cities:\n\n");
    reset();
    fprintf(fp, "Total revenue generated :%lld\n\n", TOTAL_REVENUE);

    fprintf(fp, "Company will be profitable in %d years\n\n\n\n", (y / (TOTAL_REVENUE * 12)) + 1);

    fprintf(fp, "Shortest Path from PowerGrid to all cities:\n\n");
    dijkstra2(powergrid_city_array, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from colony 1 in HUBLI \n\n");
    reset();
    fprintf(fp, "Shortest path from colony 1 in HUBLI \n\n");
    dijkstra1(hubli, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from colony 1 in DHARWAD \n\n");
    reset();
    fprintf(fp, "Shortest path from colony 1 in DHARWAD \n\n");
    dijkstra1(dharwad, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from colony 1 in NAVALGUND \n\n");
    reset();
    fprintf(fp, "Shortest path from colony 1 in NAVALGUND \n\n");
    dijkstra1(navalgund, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 1 in HUBLI \n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 1 in HUBLI \n\n");
    dijkstra(h0, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 2 in HUBLI\n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 2 in HUBLI\n\n");
    dijkstra(h1, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 3 in HUBLI\n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 3 in HUBLI\n\n");
    dijkstra(h2, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 4 in HUBLI\n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 4 in HUBLI\n\n");
    dijkstra(h3, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 1 in DHARWAD \n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 1 in DHARWAD \n\n");
    dijkstra(d0, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 2 in DHARWAD\n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 2 in DHARWAD\n\n");
    dijkstra(d1, 0);
    printf("\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 3 in DHARWAD\n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 3 in DHARWAD\n\n");
    dijkstra(d2, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 4 in DHARWAD\n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 4 in DHARWAD\n\n");
    dijkstra(d3, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 1 in NAVALGUND \n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 1 in NAVALGUND \n\n");
    dijkstra(n0, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 2 in NAVALGUND\n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 2 in NAVALGUND\n\n");
    dijkstra(n1, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 3 in NAVALGUND\n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 3 in NAVALGUND\n\n");
    dijkstra(n2, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    yellow();
    printf("Shortest path from house 0 in Colony 4 in NAVALGUND\n\n");
    reset();
    fprintf(fp, "Shortest path from house 0 in Colony 4 in NAVALGUND\n\n");
    dijkstra(n3, 0);
    printf("\n\n");
    fprintf(fp, "\n\n");
    quick(hA, 0, 15);
    yellow();
    printf("Sorting of Houses of every Colony on basis of Units Consumed \n\n");
    reset();
    purple();
    printf("Colony 1(HUBLI)\n\n");
    reset();
      fprintf(fp,"Sorting of Houses of every Colony  on basis of Units Consumed \n\n");
      fprintf(fp,"Colony 1(HUBLI)\n\n");

    for (int i = 0; i < 15; i++)
    {
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", hA[i].name, hA[i].house_num, hA[i].units_consumed, hA[i].amount_per_unit);
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", hA[i].name, hA[i].house_num, hA[i].units_consumed, hA[i].amount_per_unit);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    quick(hB, 0, 15);
    purple();
   printf("Colony 2(HUBLI)\n\n");
   reset();
   fprintf(fp,"Colony 2(HUBLI)\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", hB[i].name, hB[i].house_num, hB[i].units_consumed, hB[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", hB[i].name, hB[i].house_num, hB[i].units_consumed, hB[i].amount_per_unit);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    quick(hC, 0, 15);
   purple();
  printf("Colony 3(HUBLI)\n\n");
  reset();
    fprintf(fp,"Colony 3(HUBLI)\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", hC[i].name, hC[i].house_num, hC[i].units_consumed, hC[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", hC[i].name, hC[i].house_num, hC[i].units_consumed, hC[i].amount_per_unit);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    quick(hD, 0, 15);
  purple();
  printf("Colony 4(HUBLI)\n\n");
  reset();
    fprintf(fp,"Colony 4(HUBLI)\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", hD[i].name, hD[i].house_num, hD[i].units_consumed, hD[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", hD[i].name, hD[i].house_num, hD[i].units_consumed, hD[i].amount_per_unit);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    quick(dA, 0, 15);

    purple();
   printf("Colony 1(DHARWAD)\n\n");
   reset();
    fprintf(fp,"Colony 1(DHARWAD)\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", dA[i].name, dA[i].house_num, dA[i].units_consumed, dA[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", dA[i].name, dA[i].house_num, dA[i].units_consumed, dA[i].amount_per_unit);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    quick(dB, 0, 15);

     purple();
   printf("Colony 2(DHARWAD)\n\n");
   reset();
    fprintf(fp,"Colony 2(DHARWAD)\n\n");
    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", dB[i].name, dB[i].house_num, dB[i].units_consumed, dB[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", dB[i].name, dB[i].house_num, dB[i].units_consumed, dB[i].amount_per_unit);
    }
     printf("\n\n");
     fprintf(fp,"\n\n");
    quick(dC, 0, 15);

     purple();
   printf("Colony 3(DHARWAD)\n\n");
   reset();//shreyas shubham jadi umadi
    fprintf(fp,"Colony 3(DHARWAD)\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", dC[i].name, dC[i].house_num, dC[i].units_consumed, dC[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", dC[i].name, dC[i].house_num, dC[i].units_consumed, dC[i].amount_per_unit);
    }
     printf("\n\n");
     fprintf(fp,"\n\n");
    quick(dD, 0, 15);

     purple();
   printf("Colony 4(DHARWAD)\n\n");
   reset();
    fprintf(fp,"Colony 4(DHARWAD)\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", dD[i].name, dD[i].house_num, dD[i].units_consumed, dD[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", dD[i].name, dD[i].house_num, dD[i].units_consumed, dD[i].amount_per_unit);
    }
     printf("\n\n");
     fprintf(fp,"\n\n");
    quick(nA, 0, 15);

    purple();
   printf("Colony 1(NAVALGUND)\n\n");
   reset();
    fprintf(fp,"Colony 1(NAVALGUND)\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", nA[i].name, nA[i].house_num, nA[i].units_consumed, nA[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", nA[i].name, nA[i].house_num, nA[i].units_consumed, nA[i].amount_per_unit);
    }
     printf("\n\n");
     fprintf(fp,"\n\n");
    quick(nB, 0, 15);
   purple();
printf("Colony 2(NAVALGUND)\n\n");
reset();
    fprintf(fp,"Colony 2(NAVALGUND)\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", nB[i].name, nB[i].house_num, nB[i].units_consumed, nB[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", nB[i].name, nB[i].house_num, nB[i].units_consumed, nB[i].amount_per_unit);
    }
     printf("\n\n");
     fprintf(fp,"\n\n");
    quick(nC, 0, 15);
     purple();
printf("Colony 3(NAVALGUND)\n\n");
reset();
    fprintf(fp,"Colony 3(NAVALGUND)\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", nC[i].name, nC[i].house_num, nC[i].units_consumed, nC[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", nC[i].name, nC[i].house_num, nC[i].units_consumed, nC[i].amount_per_unit);
    }
     printf("\n\n");
     fprintf(fp,"\n\n");
    quick(nD, 0, 15);
     purple();
    printf("Colony 4(NAVALGUND)\n\n");
    reset();
    fprintf(fp,"Colony 4(NAVALGUND)\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", nD[i].name, nD[i].house_num, nD[i].units_consumed, nD[i].amount_per_unit);
        fprintf(fp, "Name:-%s\tHouse No.:-%d\tUnits_consumed:-%d\tAmount_per_unit:-%d \n", nD[i].name, nD[i].house_num, nD[i].units_consumed, nD[i].amount_per_unit);
    }
     printf("\n\n");
     fprintf(fp,"\n\n");
     fprintf(fp,"\n\n");
    fclose(fp);
    return 0;
}

int minKeycolony(int key[], bool mstSet[])
{
    int min = INF, min_index;

    for (int v = 0; v < C; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMSTcolony(int parent[], int graph[C][C])
{
    int sum = 0;
    // printf("Edge \tWeight\n");
    for (int i = 1; i < C; i++)
    {
         cyan();
        printf("%d - %d \t\t%d \n", parent[i], i, graph[i][parent[i]]);
        reset();
        fprintf(fp, "%d - %d \t\t%d \n", parent[i], i, graph[i][parent[i]]);
        sum = sum + graph[i][parent[i]];
    }
    w1 = sum + w1;
    printf("\n");
    printf("Total length of wire used : %d\n\n\n", sum);
    fprintf(fp, "\n");
    fprintf(fp, "Total length of wire used : %d\n\n\n", sum);
}

void primMSTcolony(int graph[C][C])
{
    int parent[C];
    int key[C];
    bool mstSet[C];

    for (int i = 0; i < C; i++)
        key[i] = INF, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < C - 1; count++)
    {
        int u = minKeycolony(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < C; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMSTcolony(parent, graph);
}
/* here primMST name is used to compute and make minimum spanning tree among the colonies in the city */
int minKey(int key[], bool mstSet[])
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{

    //   printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    {
        cyan();
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        reset();
        fprintf(fp, "%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        sum1 = sum1 + graph[i][parent[i]];
    }
}
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INF, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

void printMST1(int parent[], int graph[V][V])
{
    green();
    printf("from--to  \t\tDistance\n");
    printf("---------------------------------\n\n");
    reset();

    for (int i = 1; i < V; i++)
    {
        cyan();
        printf("%s - %s \t%d \n", c[parent[i]], c[i], graph[i][parent[i]]);
        reset();
        fprintf(fp, "%s - %s \t%d \n", c[parent[i]], c[i], graph[i][parent[i]]);
        sum1 = sum1 + graph[i][parent[i]];
    }
}

void primMST1(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INF, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST1(parent, graph);
}

int minDistance(int dist[], bool sptSet[])
{
    int min = INF, min_index;

    for (int v = 0; v < C; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int graph[C][C], int src)
{
    int dist[C];
    bool sptSet[C];

    for (int i = 0; i < C; i++)
        dist[i] = INF, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < C - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < C; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    green();
    printf("Vertex \t Distance from Source\n");
    reset();
    fprintf(fp, "Vertex \t Distance from Source\n");
    for (int i = 0; i < C; i++)
    {
         cyan();
        printf("%d \t\t %d\n", i, dist[i]);
        reset();
        fprintf(fp, "%d \t\t %d\n", i, dist[i]);
    }
}

void dijkstra1(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INF, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance1(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    green();
    printf("Vertex \t Distance from Source\n");
    reset();
    fprintf(fp, "Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
    {
         cyan();
        printf("%d\t\t %d\n", i, dist[i]);
        reset();
        fprintf(fp, "%d\t\t %d\n", i, dist[i]);
    }
}

void dijkstra2(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INF, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance1(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    green();
    printf("Vertex \t Distance from Source\n");
    reset();
    fprintf(fp, "Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
    {
         cyan();
        printf("%7s %7d\n", c[i], dist[i]);
        reset();
        fprintf(fp, "%7s %7d\n", c[i], dist[i]);
    }
}
int minDistance1(int dist[], bool sptSet[])
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

/*reading array function for houses*/
void readFile(char *filename, int array[ROWS][COLUMNS])
{

    FILE *fp;
    int i, j;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        fprintf(fp, "Error opening file.\n");
        return 1;
    }
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            fscanf(fp, "%d", &array[i][j]);
        }
        fscanf(fp, "\n");
    }

    fclose(fp);
}

void purple()
{
    printf("\033[0;35m");
}

void green()
{
    printf("\033[0;32m");
}

void yellow()
{
    printf("\033[1;33m");
}

void cyan()
{
    printf("\033[0;36m");
}

void red()
{
    printf("\033[1;31m");
}

void white()
{
    printf("\033[0;37m");
}

void reset()
{
    printf("\033[0m");
}
/*to read 2d array for city and colonies*/
void readFile_c(char *filename, int array[ROWS][COLUMNS])
{

    FILE *fp;
    int i, j;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        printf(fp, "Error opening file.\n");
        return 1;
    }
    for (i = 0; i < ROWS1; i++)
    {
        for (j = 0; j < COLUMNS1; j++)
        {
            fscanf(fp, "%d", &array[i][j]);
        }
        fscanf(fp, "\n");
    }

    fclose(fp);
}
/*to read data of all houses we are using this functions*/
void readStruct(struct home a[], char *filename)
{
    FILE *fp;
    int i, j;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        fprintf(fp, "Error opening file.\n");
        return 1;
    }
    for (i = 0; i < N; i++)
    {
        fscanf(fp, "%s %d %d %d \n", a[i].name, &a[i].house_num, &a[i].units_consumed, &a[i].amount_per_unit);
    }

    fclose(fp);
}

int calculate_revenue_colonywise(struct home a[])
{
    int i;
    int sum = 0;
    for (i = 0; i < N; i++)
    {
        sum = sum + a[i].units_consumed * a[i].amount_per_unit;
    }
    return sum;
}
int partition(struct home a[], int l, int h)
{

    struct home temp;
    int pivot;
    pivot = a[l].units_consumed;
   int i = l;
   int j = h;
    do
    {

        do
        {
            i++;
        } while (a[i].units_consumed <= pivot);
        do
        {
            j--;
        } while (a[j].units_consumed > pivot);
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

void quick(int a[], int l, int h)
{

    int j;
    if (l < h)
    {

        j = partition(a, l, h);
        quick(a, l, j);
        quick(a, j + 1, h);
    }
}
