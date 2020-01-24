#include "grafo.h"
#include <cstddef>

Grafo::Grafo(){
    
}
Grafo::~Grafo(){
    eliminarTodoVertice();
}

void Grafo::insertarVertice(int x){
    if(vt[x].dato == -1){
        vt[x].dato = x;
    }
}

bool Grafo::buscarVertice(int x){
    if(vt[x].dato == -1) return false;
    else return true;
}

arista* buscarArista(vertice* v,int y){
    if(v->fr != NULL){
        arista* a = v->fr;
        while(a->dato != y){
            a = a->sig;
            if(a == NULL) break;
        }
        return a;

    }else return NULL;
}

void Grafo::insertarArista(int x, int y,int peso){
    if(!buscarVertice(x) || !buscarVertice(y)) return;
    //cout << "ARSITA INSERTADA" << endl;
    arista* q = new arista;
    q->dato = y;
    q->sig = NULL;
    q->peso = peso;
    
    if(vt[x].fr == NULL){
        vt[x].fr = q;
        return;
    }
    bool fnd = false;
    arista* p = vt[x].fr;
    
    while(p->sig != NULL){
        if(p->dato == y){
            fnd = true;
            break;
        }
        p = p->sig;
    }

    if(!fnd)
        if(p->dato == y)
            fnd = true;
    
    if(!fnd) p->sig = q; 
}

void Grafo::imprimirGrafo(){
    arista *a;
    for(int i =0; i < MAX; i++){
        if(vt[i].dato != -1){
            cout << vt[i].dato << " ";
            if(vt[i].fr != NULL){
                a = vt[i].fr;
                while(a != NULL){
                    cout << a->dato <<"(" << a->peso << ")" <<  " ";
                    a = a->sig;
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}


void Grafo::eliminarVertice(int x){
    if(vt[x].dato == -1) return;
    eliminarTodaArista(x);
    vt[x].fr = NULL;
    vt[x].dato = -1;
    for(int i = 0; i < MAX; i++)
        eliminarArista(i,x);
}
void Grafo::eliminarTodoVertice(){
    for(int i = 0;i < MAX;i++)
        eliminarVertice(i);
}

void Grafo::eliminarArista(int x,int y){
    arista* aAnterior = NULL;
    arista* a = vt[x].fr,*del;
    if(a != NULL){
        while(a->dato != y){
            aAnterior = a;
            a = a->sig;
            if(a == NULL) break;
        }
    }
    if(aAnterior == NULL){
        if(a != NULL){
            //PRIMER ELEMENTO
            del = a;
            vt[x].fr = a->sig;
            delete del;
        }else{
            //VACIO
        }
    }else{
        if(a != NULL){
            //ELELM MEDIO
            del = a;
            aAnterior->sig = a->sig;
            delete del;
        }else{
            //NO SE HA ENCONTRADO

        }
    }
}

void Grafo::eliminarTodaArista(int x){
    arista* a = vt[x].fr,*e;
    while(a != NULL){
        e = a;
        a = a->sig;
        delete e;
    }
    vt[x].fr = NULL;
}

void et(int x, arista* z,int memo[MAX][3],vector<int> &noInx){
    if(z == NULL){
        noInx.erase(remove(noInx.begin(), noInx.end(), x), noInx.end());
        return;
    }
    while(z != NULL){
        if(memo[z->dato][0] != -1){
            int aux = memo[x][0] + z->peso;
            if(aux < memo[z->dato][0]){
                memo[z->dato][0] = memo[x][0] + z->peso;
                memo[z->dato][1] = x;
                memo[z->dato][2] = memo[x][2] + 1;
            }

        }else{
            memo[z->dato][0] = memo[x][0] + z->peso;
            memo[z->dato][1] = x;
            memo[z->dato][2] = memo[x][2] + 1;
            noInx.push_back(z->dato);  
        }
        
        
        z = z->sig;
    }
    noInx.erase(remove(noInx.begin(), noInx.end(), x), noInx.end());
    
}

void Grafo::ll(vector<int> &noInx,int memo[MAX][3]){
    int m;
    vector<int>::iterator it;
    if(noInx.empty()) return;
    it = noInx.begin();
    m = *it;
    for(it = noInx.begin(); it != noInx.end(); ++it){
        if(memo[*it][0] < memo[m][0]) m = *it;
    }
    et(m,vt[m].fr,memo,noInx);

}

void impr(int memo[MAX][3]){
    for(int i = 0; i < MAX; i++ ){
        cout << " i: " << i  << " " <<memo[i][0] << " " << memo[i][1] << " " << memo[i][2];
        cout << endl;
    }
}

void llenar(int memo[MAX][3]){
    for(int i = 0; i < MAX; i++ ){
        memo[i][0] = -1;
        memo[i][1] = -1;
        memo[i][2] = -1;
        
    }
}

int Grafo::menorCamino(int x,int y){
    //peso acum, anterior, iteracion
    int memo[MAX][3];
    llenar(memo);
    vector<int> noInx;
    memo[x][0] = 0;
    memo[x][1] = -1;
    memo[x][2] = 0;
    noInx.push_back(x);
    while(!noInx.empty()){
        
        ll(noInx,memo);
    }
    //impr(memo);
    //IMPRESION DE INFORMACION
    /*
    cout << "camino:" << memo[y][0] << " interaciones: " << memo[y][2] << endl;
    int c = y;
    while(c != -1){
        cout << c << "->";
        c = memo[c][1];
    }
    */
    return memo[y][1];
}

int Grafo::maxTo(int x,int y,int memo[MAX]){
    
    if(vt[x].fr == NULL) return 0;

    arista* a = vt[x].fr;
    int aux;
    while(a != NULL){

        aux = memo[x] + a->peso;
        if(memo[a->dato] < aux)
            memo[a->dato] = aux;
        maxTo(a->dato,y,memo);
        a = a->sig;
    }
}

int Grafo::longestPath(int x,int y){
    if(menorCamino(x,y) == -1) return -1;
    
    int memo[MAX];

    for(int i = 0; i < MAX; i++ ){
        memo[i] = 0;
    }

    memo[x] = 0;
    maxTo(x,y,memo);
    //cout << "ans:" << memo[y] << endl;  

      
    /*
    for(int i = 0; i < MAX; i++ ){
        cout << " i: " << i  << " " <<memo[i];
        cout << endl;
    } 
    */
     
    return memo[y];
}

int Grafo::existeCaminoDist(int s,int t,int d){
    int x = longestPath(s,t);
    if(x == -1) return 0;
    if(x >= d) return 1;
    else return 0;
}

