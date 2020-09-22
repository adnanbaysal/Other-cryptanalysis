#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RNDS   4

#define fnc(a)\
for(w[a-1]=0;w[a-1]<W1_WALKS[j[a-1]][0];w[a-1]++){\
   i[a] = P[k[a-1]*4+W1_WALKS[j[a-1]][w[a-1]+1]];\
   j[a] = i[a]%4;\
   k[a] = i[a]/4;\

int parity(int);
int hw(int);
void create_lin_table();
void PRESENT4R_lin_hulls();
void PRESENT8R_lin_hulls();

int P[64] = {
   0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,
   4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,
   8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,
   12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};
            //C 5 6  B 9 0  A  D 3  E  F 8 4 7 1 2
int S[16] = {12,5,6,11,9,0,10,13,3,14,15,8,4,7,1,2};
int main(){   
   int i[32], j[31], k[31], m, s, t, w[31];
   unsigned long long HULL_CTRS[64][64] = {0};
   int W1_WALKS[4][4] = {2,0,2,0, 3,0,1,2, 3,0,1,2, 0,0,0,0};//1<<ROW_NUM gives input mask, first element in row gives output mask count
   for(i[0]=0;i[0]<64;i[0]++){
      j[0] = i[0]%4;
      k[0] = i[0]/4;
      fnc(1)
         fnc(2)
            fnc(3)
               printf("i= %2d, j = %2d, k= %2d, l = %2d\n",i[0],i[1],i[2],i[3]);
               fnc(4)
                  fnc(5)
                     fnc(6)
                        fnc(7)
                           fnc(8)
                              fnc(9)
                                 fnc(10)
                                    fnc(11)
                                       fnc(12)
                                          fnc(13)
                                             fnc(14)
                                                fnc(15)
                                                   fnc(16)
                                                      fnc(17)
                                                         fnc(18)
                                                            fnc(19)
                                                               fnc(20)
                                                                  fnc(21)
                                                                     fnc(22)
                                                                        fnc(23)
                                                                           fnc(24)
                                                                              HULL_CTRS[i[0]][i[24]]++;
                                                                              
                                                                           }
                                                                        }
                                                                     }
                                                                  }
                                                               }
                                                            }
                                                         }
                                                      }
                                                   }
                                                }
                                             }
                                          }
                                       }
                                    }
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   FILE *file;
   file = fopen("PRESENT24R_ALL_LIN_HULLS.txt","w");
   int max_ind[2] = {0};
   unsigned long long MAX = 0, MAX_CTR = 0;
   for(i[0]=0;i[0]<64;i[0]++){
      for(i[1]=0;i[1]<64;i[1]++){
         fprintf(file,"%2d --> %2d : %lld\n",i[0],i[1],HULL_CTRS[i[0]][i[1]]);
         /*if(HULL_CTRS[i[0]][i[1]]==63525) printf("%2d -> %2d\n",i[0],i[1]);*/
         if(HULL_CTRS[i[0]][i[1]]>MAX){
            MAX = HULL_CTRS[i[0]][i[1]];
            MAX_CTR = 1;
            max_ind[0] = i[0];
            max_ind[1] = i[1];
         }
         else if(HULL_CTRS[i[0]][i[1]]==MAX) MAX_CTR++;
      }
   }
   fprintf(file,"MAX = %lld with %lld pairs. e.g : %d -> %d\n",MAX,MAX_CTR,max_ind[0],max_ind[1]);
   return 0;
}

void PRESENT8R_lin_hulls(){
   int i[9], j[8], k[8], m, s, t, w[8], HULL_CTRS[64][64] = {0};
   int W1_WALKS[4][4] = {2,0,2,0, 3,0,1,2, 3,0,1,2, 0,0,0,0};//1<<ROW_NUM gives input mask, first element in row gives output mask count
   for(i[0]=0;i[0]<64;i[0]++){
      j[0] = i[0]%4;
      k[0] = i[0]/4;
      for(w[0]=0;w[0]<W1_WALKS[j[0]][0];w[0]++){
         i[1] = P[k[0]*4+W1_WALKS[j[0]][w[0]+1]];
         j[1] = i[1]%4;
         k[1] = i[1]/4;
         for(w[1]=0;w[1]<W1_WALKS[j[1]][0];w[1]++){
            i[2] = P[k[1]*4+W1_WALKS[j[1]][w[1]+1]];
            j[2] = i[2]%4;
            k[2] = i[2]/4;
            for(w[2]=0;w[2]<W1_WALKS[j[2]][0];w[2]++){
               i[3] = P[k[2]*4+W1_WALKS[j[2]][w[2]+1]];
               j[3] = i[3]%4;
               k[3] = i[3]/4;
               for(w[3]=0;w[3]<W1_WALKS[j[3]][0];w[3]++){
                  i[4] = P[k[3]*4+W1_WALKS[j[3]][w[3]+1]];
                  j[4] = i[4]%4;
                  k[4] = i[4]/4;
                  for(w[4]=0;w[4]<W1_WALKS[j[4]][0];w[4]++){
                     i[5] = P[k[4]*4+W1_WALKS[j[4]][w[4]+1]];
                     j[5] = i[5]%4;
                     k[5] = i[5]/4;
                     for(w[5]=0;w[5]<W1_WALKS[j[5]][0];w[5]++){
                        i[6] = P[k[5]*4+W1_WALKS[j[5]][w[5]+1]];
                        j[6] = i[6]%4;
                        k[6] = i[6]/4;
                        for(w[6]=0;w[6]<W1_WALKS[j[6]][0];w[6]++){
                           i[7] = P[k[6]*4+W1_WALKS[j[6]][w[6]+1]];
                           j[7] = i[7]%4;
                           k[7] = i[7]/4;
                           for(w[7]=0;w[7]<W1_WALKS[j[7]][0];w[7]++){
                              i[8] = P[k[7]*4+W1_WALKS[j[7]][w[7]+1]];
                              j[8] = i[8]%4;
                              k[8] = i[8]/4;
                              HULL_CTRS[i[0]][i[8]]++;
                           }
                        }//
                     }
                  }
               }
            }
         }
      }
   }
   int MAX = 0, MAX_CTR = 0, max_ind[2] = {0};
   for(i[0]=0;i[0]<64;i[0]++){
      for(i[1]=0;i[1]<64;i[1]++){
         if(HULL_CTRS[i[0]][i[1]]==192) printf("%2d -> %2d\n",i[0],i[1]);
      }
   }
}

void PRESENT4R_lin_hulls(){
   int i[9], j[8], k[8], m, s, t, w[8], HULL_CTRS[64][64] = {0};
   int W1_WALKS[4][4] = {2,0,2,0, 3,0,1,2, 3,0,1,2, 0,0,0,0};//1<<ROW_NUM gives input mask, first element in row gives output mask count
   for(i[0]=0;i[0]<64;i[0]++){
      j[0] = i[0]%4;
      k[0] = i[0]/4;
      for(w[0]=0;w[0]<W1_WALKS[j[0]][0];w[0]++){
         i[1] = P[k[0]*4+W1_WALKS[j[0]][w[0]+1]];
         j[1] = i[1]%4;
         k[1] = i[1]/4;
         for(w[1]=0;w[1]<W1_WALKS[j[1]][0];w[1]++){
            i[2] = P[k[1]*4+W1_WALKS[j[1]][w[1]+1]];
            j[2] = i[2]%4;
            k[2] = i[2]/4;
            for(w[2]=0;w[2]<W1_WALKS[j[2]][0];w[2]++){
               i[3] = P[k[2]*4+W1_WALKS[j[2]][w[2]+1]];
               j[3] = i[3]%4;
               k[3] = i[3]/4;
               for(w[3]=0;w[3]<W1_WALKS[j[3]][0];w[3]++){
                  i[4] = P[k[3]*4+W1_WALKS[j[3]][w[3]+1]];
                  HULL_CTRS[i[0]][i[4]]++;
               }
            }
         }
      }
   }
   int MAX = 0, MAX_CTR = 0, max_ind[2] = {0};
   for(i[0]=0;i[0]<64;i[0]++){
      for(i[1]=0;i[1]<64;i[1]++){
         if(HULL_CTRS[i[0]][i[1]]==3) printf("%2d -> %2d\n",i[0],i[1]);
      }
   }
}

void create_lin_table(){
   int i, j, k, lin_table[16][16] = {0};
   for(i=1;i<16;i++){
      for(j=1;j<16;j++){
         for(k=0;k<16;k++){
            lin_table[i][j] += parity(i&k)^parity(j&S[k])^1;
         }
      }
   }
   for(i=1;i<16;i++) for(j=1;j<16;j++) lin_table[i][j] -= 8;
   for(i=1;i<16;i++){
      for(j=1;j<16;j++) if((hw(i)==1)&&(hw(j)==1)&&(lin_table[i][j])!=0)
         printf("%d --> %d : %d\n",i,j,abs(lin_table[i][j]));
      /*printf("%2d ",abs(lin_table[i][j]));
       printf("\n");*/
   }
}

int parity(int inp){
   int out = 0;
   while (inp!=0) {
      out ^= inp&1;
      inp >>= 1;
   }
   return out;
}

int hw(int inp){
   int out = 0;
   while (inp!=0) {
      out += inp&1;
      inp >>= 1;
   }
   return out;
}
