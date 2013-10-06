#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
struct cell
{
    int x,y;
    cell();
    cell(int a,int b):x(a),y(b) {};
};
int main()
{
    ifstream fin;
    fin.open("input.txt");
    int M,N,xKing,yKing,xKnight,yKnight, count=0;
    fin>>M>>N>>xKing>>yKing>>xKnight>>yKnight;
    fin.close();
    queue<cell*> q1;
    queue<cell*> q2;
    bool visited[M][N],found=false;
    for(int i=0; i<M; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            visited[i][j]=false;
        }
    }

//////////////////////////////////////////
    cell *p=new cell(xKing,yKing);
    visited[p->y][p->x]=true;
    q2.push(p);
    cell*pt;
    while(true)
    {
        ++count;
        while(!q2.empty())
        {
            p=q2.front();
            ///////////////////Король ходит как король////////////
            if(!(p->x-1<0)) //1
            {
                if(!visited[p->y][p->x-1])
                {
                    pt=new cell(p->x-1,p->y);
                    q1.push(pt);
                    visited[p->y][p->x-1]=true;

                }

            }


            if(!(p->x-1<0||p->y-1<0)) //2
            {

                if(!visited[p->y-1][p->x-1])
                {
                    pt=new cell(p->x-1,p->y-1);
                    q1.push(pt);
                    visited[p->y-1][p->x-1]=true;
                }

            }
            if(!(p->y-1<0)) //3
            {
                if(!visited[p->y-1][p->x])
                {
                    pt=new cell(p->x,p->y-1);
                    q1.push(pt);
                    visited[p->y-1][p->x]=true;
                }


            }
            if(!(p->x+1==N||p->y-1<0)) //4
            {
                if(!visited[p->y-1][p->x+1])
                {
                    pt=new cell(p->x+1,p->y-1);
                    q1.push(pt);
                    visited[p->y-1][p->x+1]=true;
                }

            }
            if(!(p->x+1==N))//5
            {
                if(!visited[p->y][p->x+1])
                {
                    pt=new cell(p->x+1,p->y);
                    q1.push(pt);
                    visited[p->y][p->x+1]=true;
                }

            }

            if(!(p->x+1==N||p->y+1==M))//6
            {
                if(!visited[p->y+1][p->x+1])
                {
                    pt=new cell(p->x+1,p->y+1);
                    q1.push(pt);
                    visited[p->y+1][p->x+1]=true;
                }



            }
            if(!(p->y+1==M))//7
            {
                if(!visited[p->y+1][p->x])
                {
                    pt=new cell(p->x,p->y+1);
                    q1.push(pt);
                    visited[p->y+1][p->x]=true;
                }

            }
            if(!(p->x-1<0||p->y+1==M))//8
            {
                if(!visited[p->y+1][p->x-1])
                {
                    pt=new cell(p->x-1,p->y+1);
                    q1.push(pt);
                    visited[p->y+1][p->x-1]=true;
                }

            }
            q2.pop();
        }
        visited[yKnight][xKnight]=false;
        //////////////Из точек, обойдённых "по-королевски" делаем обход как конь.///////////

        while(!q1.empty())
        {
            p=q1.front();
            q1.pop();
            if(!(p->x-2<0||p->y-1<0)) //1
            {
                if(!visited[p->y-1][p->x-2])
                {
                    pt=new cell(p->x-2,p->y-1);
                    q2.push(pt);
                    visited[p->y-1][p->x-2]=true;
                    if(q2.back()->x==xKnight&&q2.back()->y==yKnight)
                    {
                        found=true;
                    }
                }

            }

            if(!(p->x-1<0||p->y-2<0)) //2
            {
                if(!visited[p->y-2][p->x-1])
                {
                    pt=new cell(p->x-1,p->y-2);
                    q2.push(pt);
                    visited[p->y-2][p->x-1]=true;
                    if(q2.back()->x==xKnight&&q2.back()->y==yKnight)
                    {
                        found=true;
                    }
                }

            }
            //
            if(!(p->x+1==N||p->y-2<0)) //3
            {
                if(!visited[p->y-2][p->x+1])
                {
                    pt=new cell(p->x+1,p->y-2);
                    q2.push(pt);
                    visited[p->y-2][p->x+1]=true;
                    if(q2.back()->x==xKnight&&q2.back()->y==yKnight)
                    {
                        found=true;
                    }
                }

            }
            //
            if(!(p->x+2>=N||p->y-1<0)) //4
            {
                if(!visited[p->y-1][p->x+2])
                {
                    pt=new cell(p->x+2,p->y-1);
                    q2.push(pt);
                    visited[p->y-1][p->x+2]=true;
                    if(q2.back()->x==xKnight&&q2.back()->y==yKnight)
                    {
                        found=true;
                    }
                }

            }
            //
            if(!(p->x+2>=N||p->y+1==M)) //5
            {
                if(!visited[p->y+1][p->x+2])
                {
                    pt=new cell(p->x+2,p->y+1);
                    q2.push(pt);
                    visited[p->y+1][p->x+2]=true;
                    if(q2.back()->x==xKnight&&q2.back()->y==yKnight)
                    {
                        found=true;
                    }
                }

            }
            //
            if(!(p->x+1>=N||p->y+2>=M)) //6
            {
                if(!visited[p->y+2][p->x+1])
                {
                    pt=new cell(p->x+1,p->y+2);
                    q2.push(pt);
                    visited[p->y+2][p->x+1]=true;
                    if(q2.back()->x==xKnight&&q2.back()->y==yKnight)
                    {
                        found=true;
                    }
                }

            }
            //
            if(!(p->x-1<0||p->y+2>=M)) //7
            {
                if(!visited[p->y+2][p->x-1])
                {
                    pt=new cell(p->x-1,p->y+2);
                    q2.push(pt);
                    visited[p->y+2][p->x-1]=true;
                    if(q2.back()->x==xKnight&&q2.back()->y==yKnight)
                    {
                        found=true;
                    }
                }

            }
            //
            if(!(p->x-2<0||p->y+1>=M)) //8
            {
                if(!visited[p->y+1][p->x-2])
                {
                    pt=new cell(p->x-2,p->y+1);
                    q2.push(pt);
                    visited[p->x-2][p->y+1]=true;
                    if(q2.back()->x==xKnight&&q2.back()->y==yKnight)
                    {
                        found=true;
                    }
                }

            }

        }
        if(found)
            break;
            //если не нашли точку с координатами коня, то начинаем опять обходить "по-королевски"
    }
    ofstream fout;
    fout.open("output.txt");
    fout<<count;
    fout.close();
    return 0;
}
