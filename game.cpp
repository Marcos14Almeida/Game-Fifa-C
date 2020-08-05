#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include<dos.h>
#include <conio.h>
#include<windows.h>
#include<time.h>

#define MAX 40//copia de palavras
#define NLIGAS 15
#define NPOSICOES 25
#define NLISTA 750
#define NTIMES 8
int FALTAS=0;     //se tiver cartoes e lesoes 1, se nao 0
//**Jogadores com mais de 20 letras ficam bugados
//**Apagar primeira linha do arquivo csv
        int n_posicoes= NPOSICOES;
        int n_times= 8;
        int n_ligas= NLIGAS;
        int n_colunas=(4*n_times)+1;
        int SIMULACAO=0;//n jogos a simular	
int ano=2020,rodada=1,fase=1,ano_inicial=ano-1;
int campeonato=0;//Liga nacional
int timea=0,timeb;
 int time_adv,liga,vitoria,empate,resul;
 int resultado,meu_jogo;
 int liga1,liga2,time1,time2;
int vitoria_champions;
int i=1,x,y,z,n,posicao,j,k,op;
int auxiliar_int,variavel;
int meutimechampions;
int rebaixado1,acesso1,rebaixado2,acesso2;
int rebaixado1b,acesso1b,rebaixado2b,acesso2b;
char auxiliar[MAX];
int score,final=0; 
int minha_liga,ligab,minha_posicao[30];
int status[25],invicto=1;
int p_cres[NLIGAS][NPOSICOES];
float rnk_cres[NLIGAS][NPOSICOES],auxiliar_float; 
int chave1,chave2,chave3,chave4,chave5,chave6,chave7,chave8;
int var_n_ligas;
int substituir=0;
int primeira_vez=1;
float rnk[NLIGAS][NPOSICOES],idade_med,grana=0; 
int pts[NLIGAS][NPOSICOES];    
int contrato=14,amarelo[NLIGAS][8][NPOSICOES],vermelho[NLIGAS][8][NPOSICOES],machucado[NLIGAS][8][NPOSICOES],jogados[NLIGAS][8][NPOSICOES];       
char artilheiro[30][NPOSICOES*NLIGAS*NTIMES][MAX],artilheiro_liga[30][NPOSICOES*NTIMES][MAX];
char melhor_mundo[30][7][MAX];
int gols_cres_liga[30][NPOSICOES*NTIMES]={{0}};
int idade[NLIGAS][8][NPOSICOES],overall[NLIGAS][8][NPOSICOES],overallMax[NLIGAS][8][NPOSICOES],gols[NLIGAS][8][NPOSICOES]={{{0}}},gols_cres[30][NPOSICOES*NLIGAS*NTIMES]={{0}},gols_feitos_cres[NLIGAS][8]={{0}},gols_tomados_cres[NLIGAS][8]={{0}},gols_feitos[NLIGAS][8]={{0}},gols_tomados[NLIGAS][8]={{0}};
float preco[NLIGAS][8][NPOSICOES]; 
char jog[NLIGAS][8][NPOSICOES][MAX],position[NLIGAS][8][NPOSICOES][10];  //ligas; times; posicoes; tam palavra         
char a[NLIGAS][NPOSICOES][70][100];//numero de ligas; numero de posiçoes; numero de times *(nome,idade,pos,overall);   numero caracteres do nome
char ntime_cres[NLIGAS][20][MAX],champions[NLIGAS][MAX],nacional[30][NLIGAS][MAX],libertadores[NLIGAS][MAX];
int champ_ou_liberta;
char campeao[30][MAX],vice[30][MAX],terceiro[30][MAX],quarto[30][MAX];

//mudar linha 400 de jovens se acrecentar mais nomes
#define n_jovens 400
char jovens[n_jovens][MAX]={"Schumacher","Ayrton","Felipe Massa","Barrichello","Hamilton","Kloop","Jerkovic","Dunlop","Zajec","Michelin","Usain Bolt","Obama","Donaghy","Castaneda","Ezio","Kratos","Larios","Drake","Coppell","Camacho","Satrustegui","Silvio Santos","Banksy","Amunike","Mancine","Ramiro",
					   "Edinho","Scirea","Cabrini","Allofs","Gauss","Dremmler","Laplace","Magath","Trosero","Chad Smith","Flea","Trivium","Jim Carrey","Pumpido","Csuhay","Balint","Smolarek","Hong Myung","Magnussen","Esteban Ocon","Ricciardo","Faustao","Aécio","Kavanaugh","Anthony","Roberto","Ambrosi",
					   "Collovati","Eyobo","Mommens","Van der Elst","Couriol","Putin","Zaffarani","Edgar","Maceda","Buryak","Onana","Enoka","Aoudou","Oblitas","Leguia","Ederson","Kenan","Tom Brady","Tsitsipas","Verstappen","Sirotkin","Yaseem","Daciolo","Haddad","Mohhamed Ali","Kubala","Ramirez",
					   "StephanCurry","JamesHarden","Kerekes","Masny","Romantsev","YuriGagarin","Petkovic","Heinz","Schaeffler","Samsung","Petrescu","Miguel","Talles","Del Potro","Ljung","Seol","Lance Stroll","Vandoorne","El Ghany","Papagaio","Matarazzo","Ciro Gomes","Jebren","Asprilla","Peralta",
					   "Kremenliev","Galindo","Hottiger","Basualdo","Haesller","Nilis","Mussi","Dahlin","Ostalaza","Maboang","Ceulemans","Balboa","Herzog","Chovanek","Di Cavalcanti","Djokovic","Zverev","Nishikori","Valterri Bottas","Hassan","Dumont","Bolsonaro","Tom Meighan","Jesualdo","Esorenea",
					   "Hyeong","Kyrgios","Lucas Pouille","Gael Monfils","Robin Haase","KimiRaikonnen","Niki Lauda","Fucsovics","Makek Jaziris","Andrey Rublev","Wawrinka","Lorenzo Medici","Dutra","Grosjean","Charles Leclerc","Turano","Darbellay","Rocheteau","Alepo","Sergio Pizzorno","Escobar",
					   "Berdoll","Lubanski","Antonio Neto","Bonhof","Raimar","Konopka","Donelli","Gabriel Noga","Bettega","Tardelli","Várady","Bertoni","Lugo","Mendizábal","Reyes","Hejazi","Santillana","Nordqvist","Labarthe","Ghasempour","Doesburg","Lubse","Boskamp","Julien Bargeton",
					   "Rivellino","Falcão","Oberdan","Edmundo","Beckham","Henry","Shevchenko","Drogba","Ballack","Liechstein","Humberto","Belarus","Onopko","Pavel Nedved","Del Piero","Puyol","Alencar","Park Ji-Sung","Ho Min Cheng","Mbeba","Antetokuompo","LaMarc","Beethoven","Mike Tyson",
					   "Kurchaw","Lubeque","Tanahiro Nomura","Brock","Xavier","Oscar Ortega","Van Vleuten","Saunderson","Lopetegui","Azuperes","Emmanuel Maurel","Janowski","Robert Half","Coulthard","Dana Hill","Banksy","Chatillon","Lucas Camargo","Allejo","Bocardi","Daniel Costa","Ambris",
					   "Brolin","Letchkov","Belodici","BuchWald","Porcello","Kiriakov","Mild Kamark","Houtchev","Wegerle","Al Jawad","Eguavoen","Nwanu","Porzingis","Gaviria","Mfede","Falatah","Bregy Sforza","Goicoetxa","Basualdo","Staunton","Mykland","Sorloth","Van Himst","Fjortoft","Thorstvedt",
					   "Arnaldo","Geralt de Rivia","Zion Cerbi","Siakam","Franklin","Terada","Imagawa","Rosseto","Keysson","Ivan","Roberto Leal","Caligula","Ragnar","Magni","Modi","Mimir","Ragnarok","Svartelheim","Maroon Charles","Deivid","Fernando Lima","Rexona","Lamar Terry","Alex Hunter",
					   "Tyr","Guerraia","Sandro","Casagrande","Tyrone","Totodile","Sentret","Lapras","Alakazan","Ekans","Doduo","Cloyster","McHale","Drew Brees","Fagundes","Beto Cardoso","Tuco","Lineu","Agostinho","Bencola","JJ Watt","Stan Lee","Adam Smith","Mário Freitas","Bruno Covas",
					   "Dmitriaev","Suber","Matthaeus","Felipe Ramos","Vitao","Bruno Rodrigo","Gordon Ramsay","Growlithe","Cyndaquil","Ji Park","Lee Ming","Patric Oliveira","Ademir","Aguilera","Juan Carlos","Miguel Torres","Alessandro","Castaneda","Barbibieri","Fogaca","Paiol","Lucas Ramos"};
char ntime[16][10][20]={
{"","    ","      ","","      ","       "," ","     ","     "},
{"La Liga       ","Real Madrid    ","Barcelona      ","Atletico Madrid","Valencia       ","Sevilla        ","Athetic Bilbao ","Real Betis     ","Villarreal     "},
{"Calcio Serie A","Juventus       ","Napoli         ","Roma           ","Internazionale ","Milan          ","Lazio          ","Fiorentina     ","Torino         "},
{"Premier League","Man. City      ","Tottenham      ","Man. United    ","Chelsea        ","Liverpool      ","Arsenal        ","Everton        ","West Ham       "},
{"Bundesliga    ","Bayern Munique ","Bor. Dortmund  ","Schalke-04     ","B. Leverkusen  ","RB Leipzig     ","B. Monchenglad.","Hoffenheim     ","Werder Bremen  "},
{"Ligue 1       ","PSG            ","Monaco         ","O. Marselha    ","Lyon           ","Nice           ","Bordeaux       ","Lille          ","Saint-Ettienne "},
{"Eu. Ocidental ","Porto          ","Benfica        ","Sporting       ","Ajax           ","Feyenoord      ","PSV            ","Celtic         ","Anderlecht     "},
{"Eu. Oriental  ","Besiktas       ","Fenerbahce     ","Galatasaray    ","Shaktar Donetsk","Zenit          ","CSKA           ","Spartak Moscow ","Olympiakos     "},
{"Brasileirao-A ","Palmeiras      ","Corinthians    ","Sao Paulo      ","Santos         ","Cruzeiro       ","Gremio         ","Internacional  ","Flamengo       "},
{"Brasileirao-B ","Fluminense     ","Botafogo       ","Vasco          ","Atletico-MG    ","A. Paranaense  ","Coritiba       ","Fortaleza      ","Bahia          "},
{"Argentina     ","Boca Juniors   ","River Plate    ","Racing         ","San Lorenzo    ","Independiente  ","Estudiantes    ","Rosario Central","NOB            "},
{"Colombia      ","A. Nacional    ","America de Cali","Santa Fe       ","Junior FC      ","Millonarios    ","I. Medellin    ","Deportivo Cali ","Once Caldas    "},
{"Mercosul      ","Nacional       ","Penarol        ","Olimpia        ","Cerro Porteno  ","Libertad       ","Colo-Colo      ","LaU            ","U. Catolica    "},
{"Copa Andes    ","LDU            ","Barcelona-EQU  ","Emelec         ","I. Del Valle   ","Alianza Lima   ","Sport. Cristal ","Bolivar        ","Cienciano      "},
{"Premiership   ","Leicester      ","Newcastle      ","Wolves         ","Southampton    ","Aston Villa    ","Watford        ","Fulham         ","Crystal Palace "},
}; 
    char valor[800],*token, linha;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void textcolor(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    //0 preto
    //1 azul forte
    //2 verde forte
    //3 azul claro
    //4 vermelho
    //5 roxo
    //6 beje/amarelo 
    //7 branco terminal
    //8 cinza
    //9 azul neutro
    //10 verde neutro
    //11 verde agua / azul bem claro
    //12 salmao
    //13 roxo escuro
    //14 amarelo claro
    //15 branco
     return;
}
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int tabela(char nome[MAX]){                //Texto   / Background
             if(strcmp(nome,"Real Madrid    ")==0)textcolor(0,15);    if(strcmp(nome,"Barcelona      ")==0)textcolor(12,1);
 		     if(strcmp(nome,"Atletico Madrid")==0)textcolor(12,15);   if(strcmp(nome,"Valencia       ")==0)textcolor(14,0);
 		     if(strcmp(nome,"Sevilla        ")==0)textcolor(15,4);    if(strcmp(nome,"Real Betis     ")==0)textcolor(15,2);
 		     if(strcmp(nome,"Athetic Bilbao ")==0)textcolor(7,4);     if(strcmp(nome,"Villarreal     ")==0)textcolor(0,6);
 		     
 		     if(strcmp(nome,"Juventus       ")==0)textcolor(15,0);    if(strcmp(nome,"Napoli         ")==0)textcolor(0,11);
 		     if(strcmp(nome,"Roma           ")==0)textcolor(6,3);     if(strcmp(nome,"Milan          ")==0)textcolor(4,0);
 		     if(strcmp(nome,"Internazionale ")==0)textcolor(0,1);     if(strcmp(nome,"Lazio          ")==0)textcolor(11,9);
 		     if(strcmp(nome,"Fiorentina     ")==0)textcolor(15,5);    if(strcmp(nome,"Torino         ")==0)textcolor(15,3);
 		     
 		     if(strcmp(nome,"Tottenham      ")==0)textcolor(8,15);    if(strcmp(nome,"Man. United    ")==0)textcolor(0,4);
 		     if(strcmp(nome,"Chelsea        ")==0)textcolor(15,1);    if(strcmp(nome,"Man. City      ")==0)textcolor(0,11);	
			 if(strcmp(nome,"Liverpool      ")==0)textcolor(15,4);    if(strcmp(nome,"Arsenal        ")==0)textcolor(4,15);
 		     if(strcmp(nome,"Everton        ")==0)textcolor(15,1);    if(strcmp(nome,"West Ham       ")==0)textcolor(6,13);
 		     
 		     if(strcmp(nome,"Bayern Munique ")==0)textcolor(15,4);    if(strcmp(nome,"Bor. Dortmund  ")==0)textcolor(0,6);
 		     if(strcmp(nome,"Schalke-04     ")==0)textcolor(15,1);    if(strcmp(nome,"B. Leverkusen  ")==0)textcolor(4,0);
 		     if(strcmp(nome,"RB Leipzig     ")==0)textcolor(4,15);	  if(strcmp(nome,"B. Monchenglad.")==0)textcolor(2,0);
 		     if(strcmp(nome,"Werder Bremen  ")==0)textcolor(15,2);    if(strcmp(nome,"Hoffenheim     ")==0)textcolor(1,15);
 		     
 		     if(strcmp(nome,"PSG            ")==0)textcolor(1,12);    if(strcmp(nome,"Monaco         ")==0)textcolor(15,4);
 		     if(strcmp(nome,"Nice           ")==0)textcolor(4,0); 	  if(strcmp(nome,"O. Marselha    ")==0)textcolor(0,11);
 		     if(strcmp(nome,"Lyon           ")==0)textcolor(1,15);    if(strcmp(nome,"Bordeaux       ")==0)textcolor(15,1);
 		     if(strcmp(nome,"Lille          ")==0)textcolor(4,7);     if(strcmp(nome,"Saint-Ettienne ")==0)textcolor(0,2);
 		     
 		     if(strcmp(nome,"Porto          ")==0)textcolor(15,1);   if(strcmp(nome,"Benfica        ")==0)textcolor(15,4);
 		     if(strcmp(nome,"Sporting       ")==0)textcolor(10,2);
 		     if(strcmp(nome,"Ajax           ")==0)textcolor(15,4);   if(strcmp(nome,"PSV            ")==0)textcolor(4,15);
 		     if(strcmp(nome,"Feyenoord      ")==0)textcolor(4,15);
 		     if(strcmp(nome,"Anderlecht     ")==0)textcolor(15,5);
 		     if(strcmp(nome,"Celtic         ")==0)textcolor(2,15);
 		     if(strcmp(nome,"Fenerbahce     ")==0)textcolor(6,1);    if(strcmp(nome,"Galatasaray    ")==0)textcolor(6,3); if(strcmp(nome,"Besiktas        ")==0)textcolor(15,0);
 		     if(strcmp(nome,"Shaktar Donetsk")==0)textcolor(0,14);   if(strcmp(nome,"CSKA           ")==0)textcolor(4,1); if(strcmp(nome,"Zenit          ")==0)textcolor(0,11);
 		     if(strcmp(nome,"Spartak Moscow ")==0)textcolor(15,4);   if(strcmp(nome,"Olympiakos     ")==0)textcolor(4,15);
 		     
 		     if(strcmp(nome,"Palmeiras      ")==0)textcolor(15,2);   if(strcmp(nome,"Santos         ")==0)textcolor(0,15);
 		     if(strcmp(nome,"Corinthians    ")==0)textcolor(15,0);   if(strcmp(nome,"Vasco          ")==0)textcolor(15,0);
 		     if(strcmp(nome,"Sao Paulo      ")==0)textcolor(0,4);    if(strcmp(nome,"Cruzeiro       ")==0)textcolor(15,1);
 		     if(strcmp(nome,"Gremio         ")==0)textcolor(0,9);    if(strcmp(nome,"Internacional  ")==0)textcolor(15,4); 		     
 		     if(strcmp(nome,"Flamengo       ")==0)textcolor(4,0);    if(strcmp(nome,"Fluminense     ")==0)textcolor(4,2);
 		     if(strcmp(nome,"Botafogo       ")==0)textcolor(0,8);    if(strcmp(nome,"Atletico-MG    ")==0)textcolor(15,8);
 		     if(strcmp(nome,"A. Paranaense  ")==0)textcolor(4,0);    if(strcmp(nome,"Coritiba       ")==0)textcolor(2,15);
 		     if(strcmp(nome,"Fortaleza      ")==0)textcolor(1,12);   if(strcmp(nome,"Bahia          ")==0)textcolor(1,15);
 		     
 		     if(strcmp(nome,"Racing         ")==0)textcolor(0,11); if(strcmp(nome,"San Lorenzo    ")==0)textcolor(9,3);
 		     if(strcmp(nome,"Boca Juniors   ")==0)textcolor(6,1);  if(strcmp(nome,"River Plate    ")==0)textcolor(4,15);  
			 if(strcmp(nome,"Independiente  ")==0)textcolor(15,4); if(strcmp(nome,"Estudiantes    ")==0)textcolor(15,3); 
			 if(strcmp(nome,"Rosario Central")==0)textcolor(1,6);  if(strcmp(nome,"NOB            ")==0)textcolor(4,0);
			
			 if(strcmp(nome,"A. Nacional    ")==0)textcolor(2,15); if(strcmp(nome,"America de Cali")==0)textcolor(15,4);
			 if(strcmp(nome,"Junior FC      ")==0)textcolor(3,9);  if(strcmp(nome,"Millonarios    ")==0)textcolor(15,1);
			 if(strcmp(nome,"Once Caldas    ")==0)textcolor(0,15); if(strcmp(nome,"Deportivo Cali ")==0)textcolor(15,2);
			 if(strcmp(nome,"I. Medellin    ")==0)textcolor(9,3); if(strcmp(nome,"Santa Fe       ")==0)textcolor(4,15);
			  
			 if(strcmp(nome,"Penarol        ")==0)textcolor(0,6);   if(strcmp(nome,"Nacional       ")==0)textcolor(15,1);
			 if(strcmp(nome,"Olimpia        ")==0)textcolor(15,0);  if(strcmp(nome,"Cerro Porteno  ")==0)textcolor(3,9);
			 if(strcmp(nome,"Colo-Colo      ")==0)textcolor(8,15);  if(strcmp(nome,"LaU            ")==0)textcolor(15,1); if(strcmp(nome,"U. Catolica    ")==0)textcolor(1,15);
			 if(strcmp(nome,"Bolivar        ")==0)textcolor(0,11);  if(strcmp(nome,"Libertad       ")==0)textcolor(0,8);			 
			 if(strcmp(nome,"LDU            ")==0)textcolor(0,15);  if(strcmp(nome,"Barcelona-EQU  ")==0)textcolor(3,6);
			 if(strcmp(nome,"Sport. Cristal ")==0)textcolor(0,11);  if(strcmp(nome,"Universitario  ")==0)textcolor(4,15);
			 if(strcmp(nome,"Emelec         ")==0)textcolor(11,1);  if(strcmp(nome,"Alianza Lima   ")==0)textcolor(15,9);  
			 if(strcmp(nome,"Cienciano      ")==0)textcolor(15,1);  if(strcmp(nome,"I. Del Valle   ")==0)textcolor(1,0);
			  		     
 		     if(strcmp(nome,"Leicester      ")==0)textcolor(15,1); if(strcmp(nome,"Southampton    ")==0)textcolor(4,15);
 		     if(strcmp(nome,"Newcastle      ")==0)textcolor(15,0); if(strcmp(nome,"Watford        ")==0)textcolor(0,6); 
 		     if(strcmp(nome,"Wolves         ")==0)textcolor(0,14); if(strcmp(nome,"Aston Villa    ")==0)textcolor(11,5);
 		     if(strcmp(nome,"Crystal Palace ")==0)textcolor(12,1); if(strcmp(nome,"Fulham         ")==0)textcolor(0,15);
				 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 int simula_jogo(){
if(campeonato<=1){ 
	if(resul>9){vitoria=90;empate=95;	}	
 	if(resul>7){vitoria=85;empate=95;	}	 
    if(resul<=7){vitoria=80;empate=90;	}	 
	if(resul<=5){vitoria=70;empate=85;	}	  
	if(resul<=3){vitoria=60;empate=80;	}	 
	if(resul<=2){vitoria=50;empate=75;	}    
	if(resul<=1){vitoria=42;empate=70;	}
	if(resul==0){vitoria=35;empate=65;	} 
	if(resul<=-1){vitoria=30;empate=58;	}    
	if(resul<=-2){vitoria=25;empate=50;}  
	if(resul<=-3){vitoria=20;empate=40;	}
	if(resul<=-5){vitoria=15;empate=30;	}
	if(resul<=-7){vitoria=10;empate=20;	} 
	if(resul<-7){vitoria=5;empate=15;	}
	if(resul<-9){vitoria=5;empate=10;	}
	}  
if(campeonato==2){
     if(resul>6){vitoria=90; }	      if(resul<=6){vitoria=80;	}	    if(resul<=4){vitoria=75;	}	 if(resul<=2){vitoria=65;	}	 	if(resul<=1){vitoria=50;}  
	 if(resul<=-2){vitoria=35;}       if(resul<=-4){vitoria=25;	}       if(resul<=-5){vitoria=20;	}    if(resul<=-6){vitoria=10;	}   
	}
 }
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 int busca_time(int a, int b){
 		   				for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){         
					 for(k=1;k<=n_times;k++){  
				   if(strcmp(ntime[var_n_ligas][k],champions[a])==0) {time1=k; liga1=var_n_ligas;	  } 	  
                   if(strcmp(ntime[var_n_ligas][k],champions[b])==0) {time2=k; liga2=var_n_ligas;	  }     }}
 }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
 int simula_gols(int resultado, int meu_jogo,  int liga1, int liga2, int time1, int time2){
	 	int quem_fez,var_gols,n_gols,n_gols_adv,valor;
	 	//cartoes amarelos, vermelhos e expulsoes
	 	if(meu_jogo==0){
	 		//aumenta o numero de jogos do goleiro
	 	 jogados[liga1][time1][1]++;jogados[liga2][time2][1]++;
	 	 //atualiza os cartoes, lesoes
	 	 for(x=2;x<=n_posicoes;x++){
 	 	 	if(amarelo[liga1][time1][x]>=3)amarelo[liga1][time1][x]=0;if(amarelo[liga2][time2][x]>=3)amarelo[liga2][time2][x]=0;
		    vermelho[liga1][time1][x]=0;                                                             vermelho[liga2][time2][x]=0;
			if(machucado[liga1][time1][x]>0) machucado[liga1][time1][x]--;if(machucado[liga2][time2][x]>0) machucado[liga2][time2][x]--;
		}
 	 	 for(x=2;x<=11;x++){
		   jogados[liga1][time1][x]++;jogados[liga2][time2][x]++;	 			 
			 	variavel=rand()%80-78;if(variavel<=0)variavel=0; vermelho[liga1][time1][x]+=variavel;
			 	variavel=rand()%70-68;if(variavel<=0)variavel=0; else{variavel=rand()%12;} machucado[liga1][time1][x]+=variavel;
				 auxiliar[x]=rand()%5-3;  if(auxiliar[x]<=0)auxiliar[x]=0; amarelo[liga1][time1][x]+=auxiliar[x];
				 variavel=rand()%80-78;if(variavel<=0)variavel=0; vermelho[liga2][time2][x]+=variavel;
				 variavel=rand()%70-68;if(variavel<=0)variavel=0; else{variavel=rand()%12;} machucado[liga2][time2][x]+=variavel;
				 auxiliar[x]=rand()%5-3;  if(auxiliar[x]<=0)auxiliar[x]=0; amarelo[liga2][time2][x]+=auxiliar[x];  
							
							}}
	 if(campeonato==1 && meu_jogo==1){time1=n;}//Se estiver meu time na champions league

 			var_gols=rand()%100;
 			
        if (var_gols>96){n_gols=5;}
        else if (var_gols>90){n_gols=4;}
        else if (var_gols>75){n_gols=3;}
        else if (var_gols>40){n_gols=2;}
        else {n_gols=1;}
        
        var_gols=rand()%100;
        if (var_gols>92){n_gols_adv=3;}
        else if (var_gols>80){n_gols_adv=2;}
        else if (var_gols>40){n_gols_adv=1;}
        else {n_gols_adv=0;} 
        if (n_gols_adv>=n_gols){n_gols_adv=n_gols-1;}
		
		if (resultado==2){n_gols--;n_gols_adv=n_gols;}  
		if (resultado==3){auxiliar_int=n_gols;n_gols=n_gols_adv;n_gols_adv=auxiliar_int;}  
		
		if(meu_jogo==1){printf("  ");tabela(ntime[liga1][time1]);printf("%s",ntime[liga1][time1]);
						textcolor(7,0);printf("(%.1f) %d x %d (%.1f)",rnk[liga1][time1],n_gols,n_gols_adv,rnk[liga2][time2]);  
						tabela(ntime[liga2][time2]);printf("%s",ntime[liga2][time2]);textcolor(7,0);}
        if(campeonato>=1 && meu_jogo==0){printf("\n %s %d x %d %s",ntime[liga1][time1],n_gols,n_gols_adv,ntime[liga2][time2]);  } //Mostra os resultados da rodada
        
        if(meu_jogo==1){printf("\nGols:");}
        while(n_gols>0){n_gols--; 
				     	quem_fez=rand()%100;				     	
		if(quem_fez<=100 && quem_fez>97){valor=2;}//L
		if(quem_fez<=97 && quem_fez>94){valor=3;}//ZAG
		if(quem_fez<=94 && quem_fez>91){valor=4;}//ZAG
		if(quem_fez<=91 && quem_fez>88){valor=5;}//L
		if(quem_fez<=88 && quem_fez>81){valor=6;}//VOL
		if(quem_fez<=81 && quem_fez>74){valor=7;}//VOL
		if(quem_fez<=74 && quem_fez>60){valor=8;}//MEI
		if(quem_fez<=60 && quem_fez>46){valor=9;}//MEI
		if(quem_fez<=46 && quem_fez>23){valor=10;}//ATA
		if(quem_fez<=23){valor=11;}//ATA
		gols[liga1][time1][valor]++;
		gols_feitos[liga1][time1]++;
		gols_tomados[liga2][time2]++;
			if(meu_jogo==1){	printf("%s",jog[liga1][time1][valor]);}
	}
	if(meu_jogo==1){printf("\nGols:");}
        while(n_gols_adv>0){n_gols_adv--; 
				     	quem_fez=rand()%100;
		if(quem_fez<=100 && quem_fez>97){valor=2;}//L
		if(quem_fez<=97 && quem_fez>94){valor=3;}//ZAG
		if(quem_fez<=94 && quem_fez>91){valor=4;}//ZAG
		if(quem_fez<=91 && quem_fez>88){valor=5;}//L
		if(quem_fez<=88 && quem_fez>81){valor=6;}//VOL
		if(quem_fez<=81 && quem_fez>74){valor=7;}//VOL
		if(quem_fez<=74 && quem_fez>60){valor=8;}//MEI
		if(quem_fez<=60 && quem_fez>46){valor=9;}//MEI
		if(quem_fez<=46 && quem_fez>23){valor=10;}//ATA
		if(quem_fez<=23){valor=11;}//ATA
		gols[liga2][time2][valor]++;
		gols_feitos[liga2][time2]++;
		gols_tomados[liga1][time1]++;
				if(meu_jogo==1){	printf("%s",jog[liga2][time2][valor]);}
	}
	
 } 
   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
 int preco_jogador(){
 	//Valor dos jogadores
for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){         
for(x=1;x<=n_times;x++){       
for(y=1;y<=n_posicoes;y++){
	
			if(overall[var_n_ligas][x][y]<=63){preco[var_n_ligas][x][y]=0.2;}
			if(overall[var_n_ligas][x][y]==64){preco[var_n_ligas][x][y]=0.5;}
			if(overall[var_n_ligas][x][y]==65){preco[var_n_ligas][x][y]=1;}
			if(overall[var_n_ligas][x][y]==66){preco[var_n_ligas][x][y]=2;}
			if(overall[var_n_ligas][x][y]==67){preco[var_n_ligas][x][y]=3;}
			if(overall[var_n_ligas][x][y]==68){preco[var_n_ligas][x][y]=5;}
			if(overall[var_n_ligas][x][y]==69){preco[var_n_ligas][x][y]=7;}
			if(overall[var_n_ligas][x][y]==70){preco[var_n_ligas][x][y]=9;}
			if(overall[var_n_ligas][x][y]==71){preco[var_n_ligas][x][y]=12;}
			if(overall[var_n_ligas][x][y]==72){preco[var_n_ligas][x][y]=15;}
			if(overall[var_n_ligas][x][y]==73){preco[var_n_ligas][x][y]=20;}
			if(overall[var_n_ligas][x][y]==74){preco[var_n_ligas][x][y]=25;}
			if(overall[var_n_ligas][x][y]==75){preco[var_n_ligas][x][y]=30;}
			if(overall[var_n_ligas][x][y]==76){preco[var_n_ligas][x][y]=40;}
			if(overall[var_n_ligas][x][y]==77){preco[var_n_ligas][x][y]=50;}
			if(overall[var_n_ligas][x][y]==78){preco[var_n_ligas][x][y]=60;}
			if(overall[var_n_ligas][x][y]==79){preco[var_n_ligas][x][y]=70;}
			if(overall[var_n_ligas][x][y]==80){preco[var_n_ligas][x][y]=80;}
			if(overall[var_n_ligas][x][y]==81){preco[var_n_ligas][x][y]=90;}
			if(overall[var_n_ligas][x][y]==82){preco[var_n_ligas][x][y]=105;}
			if(overall[var_n_ligas][x][y]==83){preco[var_n_ligas][x][y]=120;}
			if(overall[var_n_ligas][x][y]==84){preco[var_n_ligas][x][y]=140;}
			if(overall[var_n_ligas][x][y]==85){preco[var_n_ligas][x][y]=170;}
			if(overall[var_n_ligas][x][y]==86){preco[var_n_ligas][x][y]=200;}
			if(overall[var_n_ligas][x][y]==87){preco[var_n_ligas][x][y]=250;}
			if(overall[var_n_ligas][x][y]==88){preco[var_n_ligas][x][y]=300;}
			if(overall[var_n_ligas][x][y]==89){preco[var_n_ligas][x][y]=350;}
			if(overall[var_n_ligas][x][y]==90){preco[var_n_ligas][x][y]=400;}
			if(overall[var_n_ligas][x][y]==91){preco[var_n_ligas][x][y]=450;}
			if(overall[var_n_ligas][x][y]==92){preco[var_n_ligas][x][y]=500;}
			if(overall[var_n_ligas][x][y]==93){preco[var_n_ligas][x][y]=600;}
			if(overall[var_n_ligas][x][y]==94){preco[var_n_ligas][x][y]=700;}
			if(overall[var_n_ligas][x][y]==95){preco[var_n_ligas][x][y]=800;}
	  	if (idade[var_n_ligas][x][y]>=17){preco[var_n_ligas][x][y]=preco[var_n_ligas][x][y]*240/(idade[var_n_ligas][x][y]*idade[var_n_ligas][x][y]);}
	  	if (idade[var_n_ligas][x][y]>=32){preco[var_n_ligas][x][y]=preco[var_n_ligas][x][y]*0.9;}
	  	if (idade[var_n_ligas][x][y]>=35){preco[var_n_ligas][x][y]=preco[var_n_ligas][x][y]*0.9;}
		}
}}  
 	
 } 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                               //\\   //\\          //\\    ||     //\\      //
                              //  \\ //  \\        //  \\   ||    //  \\    //
                             //           \\      //====\\  ||   //    \\  // 
                            //             \\    //      \\ ||  //      \\//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
main(){srand( (unsigned)time(NULL) );
textcolor(7,0);
FILE *entrada;
int var_n_ligasARQ;    
for (var_n_ligasARQ=1;var_n_ligasARQ<n_ligas;var_n_ligasARQ++){ 
  
if(var_n_ligasARQ==1){
entrada = fopen( "c game fifa - Espanha.csv", "r");
    if((entrada = fopen("c game fifa - Espanha.csv", "r")) == NULL){       printf("Erro ao abrir o arquivo.\n");   }
}

if(var_n_ligasARQ==2){entrada = fopen( "c game fifa - Italia.csv", "r");}
if(var_n_ligasARQ==3){entrada = fopen( "c game fifa - Inglaterra.csv", "r");}
if(var_n_ligasARQ==4){entrada = fopen( "c game fifa - Alemanha.csv", "r");}
if(var_n_ligasARQ==5){entrada = fopen( "c game fifa - França.csv", "r");}
if(var_n_ligasARQ==6){entrada = fopen( "c game fifa - Outros.csv", "r");}
if(var_n_ligasARQ==7){entrada = fopen( "c game fifa - Oriental.csv", "r");}
if(var_n_ligasARQ==8){entrada = fopen( "c game fifa - Brasil.csv", "r");}
if(var_n_ligasARQ==9){entrada = fopen( "c game fifa - Brasil2.csv", "r");}
if(var_n_ligasARQ==10){entrada = fopen( "c game fifa - Argentina.csv", "r");}
if(var_n_ligasARQ==11){entrada = fopen( "c game fifa - Colombia.csv", "r");}
if(var_n_ligasARQ==12){entrada = fopen( "c game fifa - America Sul.csv", "r");}
if(var_n_ligasARQ==13){entrada = fopen( "c game fifa - America Sul 2.csv", "r");}
if(var_n_ligasARQ==14){entrada = fopen( "c game fifa - Premiership.csv", "r");}
    
    x=0;
while(x<=n_posicoes){//repete a iteração do goleiro aos reservas
	for(n=0;n<300;n++)//le cada char da linha aproximadamente 300
	                 {
					 fscanf(entrada,"%c",&valor[n]); 
					 	
					 								  if(valor[n]==-61){valor[n]=130;}
					 								  if(valor[n]==-87){valor[n]=2;}//é
					 								  
					 								  if((valor[n-1]==-61) && (valor[n]==-89)){valor[n-1]=64;  valor[n]=2;} //ç
					 								  if((valor[n-1]==-59) && (valor[n]==-103)){valor[n-1]='r';  valor[n]=2;} //s
					 								  if((valor[n-1]==-56) && (valor[n]==-103)){valor[n-1]='s';  valor[n]=2;} //s
					 								  if((valor[n-1]==-126) && (valor[n]==-67)){valor[n-1]='y';  valor[n]=2;} //y
					 								  if((valor[n-1]==-126) && (valor[n]==-94)){valor[n-1]=97;  valor[n]=2;} //â
					 								  if((valor[n-1]==-126) && (valor[n]==2)){valor[n-1]=130;  valor[n]=2;} //é
	               									  if((valor[n-1]==-126) && (valor[n]==-86)){valor[n-1]=101;  valor[n]=2;} //e
													  if((valor[n-1]==-126) && (valor[n]==-95)){valor[n-1]=160;  valor[n]=2;} //á
													  if((valor[n-1]==-126) && (valor[n]==-96)){valor[n-1]=133;  valor[n]=2;} //à
													  if((valor[n-1]==-126) && (valor[n]==-88)){valor[n-1]=138;  valor[n]=2;} //è
													  if((valor[n-1]==-126) && (valor[n]==-83)){valor[n-1]=161;  valor[n]=2;} //í
													  if((valor[n-1]==-126) && (valor[n]==-77)){valor[n-1]=162;  valor[n]=2;} //ó
													  if((valor[n-1]==-126) && (valor[n]==-70)){valor[n-1]=163;  valor[n]=2;} //ú
													  if((valor[n-1]==-126) && (valor[n]==-79)){valor[n-1]=164;  valor[n]=2;} //n
													  if((valor[n-1]==-126) && (valor[n]==-93)){valor[n-1]=198;  valor[n]=2;} //ã
													  if((valor[n-1]==-126) && (valor[n]==-106)){valor[n-1]=153;  valor[n]=2;} //Ö	
													  if((valor[n-1]==-126) && (valor[n]==-109)){valor[n-1]=224;  valor[n]=2;} //Ó										  
													  if((valor[n-1]==-59) && (valor[n]==-124)){valor[n-1]=164;  valor[n]=2;} //zieliNski
													  if((valor[n-1]==-59) && (valor[n]==-66)){valor[n-1]=122;  valor[n]=2;} //MandZukic
													  if((valor[n-1]==-59) && (valor[n]==-67)){valor[n-1]='Z';  valor[n]=2;} //MandZukic													  
													  if((valor[n-1]==-59) && (valor[n]==-95)){valor[n-1]=115;  valor[n]=2;} //periSic													  
													  if((valor[n-1]==-59) && (valor[n]==-96)){valor[n-1]=83;  valor[n]=2;} //Š													  
													  if((valor[n-1]==-59) && (valor[n]==-127)){valor[n-1]='L';  valor[n]=2;} //Š
													  if((valor[n-1]==99) && (valor[n]==-80)){valor[n-1]=73;  valor[n]=2;} //Ilkay
													  if((valor[n-1]==99) && (valor[n]==-32)){valor[n-1]=103;  valor[n]=2;} //GundoGan
													  if((valor[n-1]==-59) && (valor[n]==-98)){valor[n-1]=83;  valor[n]=2;} //Stefan Radu
													  if((valor[n-1]==99) && (valor[n]==-97)){valor[n-1]=103;  valor[n]=2;} //çalhanoGlou
													  if((valor[n-1]==99) && (valor[n]==-116)){valor[n-1]=67;  valor[n]=2;} //Cech
													  if((valor[n-1]==-60) && (valor[n]==-111)){valor[n-1]='d';  valor[n]=2;} //d
													  if((valor[n-1]==-60) && (valor[n]==-103)){valor[n-1]=101;  valor[n]=2;} //SzczEsny
													  if((valor[n-1]==-126) && (valor[n]==-72)){valor[n-1]=157;  valor[n]=2;} //ø
													  if((valor[n-1]==-126) && (valor[n]==-74)){valor[n-1]=148;  valor[n]=2;} //ö
													  if((valor[n-1]==-126) && (valor[n]==-75)){valor[n-1]=228;  valor[n]=2;} //õ
													  if((valor[n-1]==-126) && (valor[n]==-92)){valor[n-1]=132;  valor[n]=2;} //ä
													  if((valor[n-1]==-126) && (valor[n]==-85)){valor[n-1]=137;  valor[n]=2;} //ë
													  if((valor[n-1]==-126) && (valor[n]==-76)){valor[n-1]=147;  valor[n]=2;} //ô
													  if((valor[n-1]==-126) && (valor[n]==-90)){valor[n-1]=145;  valor[n]=2;} //æ
													  if((valor[n-1]==-126) && (valor[n]==-68)){valor[n-1]=129;  valor[n]=2;} //ü
													  if((valor[n-1]==-126) && (valor[n]==-89)){valor[n-1]=135;  valor[n]=2;} //ç													   
													  if((valor[n-1]==-126) && (valor[n]==-82)){valor[n-1]='i';  valor[n]=2;} //î
													  if((valor[n-1]==-126) && (valor[n]==-81)){valor[n-1]=139;  valor[n]=2;} //ï
													  if((valor[n-1]==-126) && (valor[n]==-80)){valor[n-1]='d';  valor[n]=2;} //sigurDson
													  if((valor[n-1]==-126) && (valor[n]==-127)){valor[n-1]=65;  valor[n]=2;} //Á
													  if((valor[n-1]==-126) && (valor[n]==-78)){valor[n-1]=149;  valor[n]=2;} //ò
													  if((valor[n-1]==-126) && (valor[n]==-119)){valor[n-1]=69;  valor[n]=2;} //É
													  if((valor[n-1]==-126) && (valor[n]==-100)){valor[n-1]='U';  valor[n]=2;} //U
				                                      if((valor[n-1]==-60) && (valor[n]==-121)){valor[n-1]=99;  valor[n]=2;} //rakitic
				                                      if((valor[n-1]==-60) && (valor[n]==-79)){valor[n-1]='i';  valor[n]=2;} //
													  if((valor[n-1]==-126) && (valor[n]==-121)){valor[n-1]=67;  valor[n]=2;} //C
													  if((valor[n-1]==-60) && (valor[n]==-122)){valor[n-1]='C';  valor[n]=2;} //C
													  if((valor[n-1]==-60) && (valor[n]==-115)){valor[n-1]=99;  valor[n]=2;} //c
													  if((valor[n-1]==-60) && (valor[n]==-80)){valor[n-1]='I';  valor[n]=2;} //g
													  if((valor[n-1]==-60) && (valor[n]==-97)){valor[n-1]='g';  valor[n]=2;} //g
													  if((valor[n-1]==-60) && (valor[n]==-123)){valor[n-1]='a';  valor[n]=2;} //DrAgowski
													  if((valor[n-1]==-60) && (valor[n]==-125)){valor[n-1]='a';  valor[n]=2;} //tAtArusanu
													  if((valor[n-1]==-59) && (valor[n]==-126)){valor[n-1]='l';  valor[n]=2;} //l
													  if((valor[n-1]==76) && (valor[n]==44)){valor[n-1]=' ';  valor[n]=44;} //L, final desnecessario**
		                                              if(valor[n]==10){n=300;x++;}//quando le a linha de baixo
								//if(x==1 && n<10){printf("%d %d STRING ----> %c /%d\n",x, n, valor[n], valor[n]);getch();}
	}
    token = strtok(valor,",");
    i=1;
    while(token!=NULL)
    {
        token=strtok(NULL,",");		
        if(token!=NULL)
        {	 //retira espaços em branco
            	   int len = strlen(token);	    
                 for (int q = 0, posicao = 0; q < len; q++, posicao++) {
                if (token[posicao] == ' ' && token[posicao] >='A' || token[posicao] ==2) {posicao++;}
                 token[q] = token[posicao];
                }
                if (x>=1){
            strcpy(a[var_n_ligasARQ][x-1][i], token);
				}
            
            //printf("%d,%d, %d---%s\n",x-1,i,var_n_ligasARQ,a[var_n_ligasARQ][x-1][i]);
            i++;
        }
    }
            
        
}//termina de ler os arquivos de texto
}//fim loop abrir arquivo
//Nome dos jovens
//termina de formatar colocando espaços	nos nomes
		for(j=0; j<=n_jovens;j++){for (posicao = 0; posicao<20;  posicao++) {if(jovens[j][posicao]==NULL) {jovens[j][posicao]=' ';} }		}
                                                                
//Pega nome do jogador  
for (var_n_ligas=0;var_n_ligas<n_ligas;var_n_ligas++){ 
for(j=1; j<n_posicoes;j++){k=1;
		for(time1=1; time1<n_colunas;time1=time1+4){// le as colunas de todos os times que sao separados de 4 em 4 (NOME, pos, ida, overall, NOME...) =time
			strcpy(jog[var_n_ligas][k][j],a[var_n_ligas][j][time1]);
			k++;} }     }
						
//Pega posicao do jogador 
for (var_n_ligas=0;var_n_ligas<n_ligas;var_n_ligas++){ 
for(j=1; j<n_posicoes;j++){k=1;
		for(time1=2; time1<n_colunas;time1=time1+4){
			for(n=0; n<strlen(a[var_n_ligas][j][time1]);n++){
			if(a[var_n_ligas][j][time1][n]=='G'&&a[var_n_ligas][j][time1][n+1]=='O'){strcpy(position[var_n_ligas][k][j],"GOL");}//procura Goleiro
			if(a[var_n_ligas][j][time1][n]=='Z'){strcpy(position[var_n_ligas][k][j],"ZAG");}//ZAG
			if(a[var_n_ligas][j][time1][n]=='L'&&a[var_n_ligas][j][time1][n+1]=='E'){strcpy(position[var_n_ligas][k][j],"LAT");}//LE
			if(a[var_n_ligas][j][time1][n]=='A'&&a[var_n_ligas][j][time1][n+1]=='D'&&a[var_n_ligas][j][time1][n+2]=='E'){strcpy(position[var_n_ligas][k][j],"LAT");}//ADE
			if(a[var_n_ligas][j][time1][n]=='A'&&a[var_n_ligas][j][time1][n+1]=='D'&&a[var_n_ligas][j][time1][n+2]=='D'){strcpy(position[var_n_ligas][k][j],"LAT");}//ADD
			if(a[var_n_ligas][j][time1][n]=='L'&&a[var_n_ligas][j][time1][n+1]=='D'){strcpy(position[var_n_ligas][k][j],"LAT");}//LD
			if(a[var_n_ligas][j][time1][n]=='V'&&a[var_n_ligas][j][time1][n+1]=='O'){strcpy(position[var_n_ligas][k][j],"VOL");}//Volante
			if(a[var_n_ligas][j][time1][n]=='M'&&a[var_n_ligas][j][time1][n+1]=='C'){strcpy(position[var_n_ligas][k][j],"MEI");}	//MC
			if(a[var_n_ligas][j][time1][n]=='M'&&a[var_n_ligas][j][time1][n+1]=='E'){strcpy(position[var_n_ligas][k][j],"MEI");}//MEI
			if(a[var_n_ligas][j][time1][n]=='M'&&a[var_n_ligas][j][time1][n+1]=='D'){strcpy(position[var_n_ligas][k][j],"MEI");}//MEI
			if(a[var_n_ligas][j][time1][n]=='P'){strcpy(position[var_n_ligas][k][j],"ATA");}							//Ponta
			if(a[var_n_ligas][j][time1][n]=='A'&&a[var_n_ligas][j][time1][n+1]=='T'){strcpy(position[var_n_ligas][k][j],"ATA");}//Atacante
			if(a[var_n_ligas][j][time1][n]=='S'&&a[var_n_ligas][j][time1][n+1]=='A'){strcpy(position[var_n_ligas][k][j],"ATA");}//Atacante
			}
			k++;} }  }	
					                                     
//Pega idade do jogador
for (var_n_ligas=0;var_n_ligas<n_ligas;var_n_ligas++){ 
for(j=1; j<n_posicoes;j++){k=1;
		for(time1=3; time1<n_colunas;time1=time1+4){
			idade[var_n_ligas][k][j]=(10*(a[var_n_ligas][j][time1][0]-48))+(a[var_n_ligas][j][time1][1]-48); 
			k++;} }}
//Pega overall do jogador	
for (var_n_ligas=0;var_n_ligas<n_ligas;var_n_ligas++){ 		
for(j=1; j<n_posicoes;j++){k=1;
		for(time1=4; time1<n_colunas;time1=time1+4){
			overall[var_n_ligas][k][j]=(10*(a[var_n_ligas][j][time1][0]-48))+(a[var_n_ligas][j][time1][1]-48); 
			k++;}                                            }}
//Pega overall max do jogador
for (var_n_ligas=0;var_n_ligas<n_ligas;var_n_ligas++){ 			
for(j=1; j<n_posicoes;j++){k=1;
		for(time1=4; time1<n_colunas;time1=time1+4){
			overallMax[var_n_ligas][k][j]=(10*(a[var_n_ligas][j][time1][2]-48))+(a[var_n_ligas][j][time1][3]-48); 
			k++;}  }}
			
			//liga brasileira e Argentina
for (k=1;k<=n_times;k++){ 			
for(j=1; j<n_posicoes;j++){	
if(idade[8][k][j]>15)overallMax[8][k][j]=overall[8][k][j]+14;
if(idade[8][k][j]>22)overallMax[8][k][j]=overall[8][k][j]+7;
if(idade[8][k][j]>30)overallMax[8][k][j]=overall[8][k][j]+2;

if(idade[9][k][j]>15)overallMax[9][k][j]=overall[9][k][j]+12;
if(idade[9][k][j]>22)overallMax[9][k][j]=overall[9][k][j]+6;
if(idade[9][k][j]>30)overallMax[9][k][j]=overall[9][k][j]+2;

if(idade[10][k][j]>15)overallMax[10][k][j]=overall[10][k][j]+11;
if(idade[10][k][j]>22)overallMax[10][k][j]=overall[10][k][j]+6;
if(idade[10][k][j]>30)overallMax[10][k][j]=overall[10][k][j]+2;
//COLOMBIA
if(idade[11][k][j]>15)overallMax[11][k][j]=overall[11][k][j]+8;
if(idade[11][k][j]>22)overallMax[11][k][j]=overall[11][k][j]+4;
if(idade[11][k][j]>30)overallMax[11][k][j]=overall[11][k][j]+2;
//SUL AMERICA
if(idade[12][k][j]>15)overallMax[12][k][j]=overall[12][k][j]+8;
if(idade[12][k][j]>22)overallMax[12][k][j]=overall[12][k][j]+4;
if(idade[12][k][j]>30)overallMax[12][k][j]=overall[12][k][j]+2;

if(idade[13][k][j]>15)overallMax[13][k][j]=overall[13][k][j]+7;
if(idade[13][k][j]>22)overallMax[13][k][j]=overall[13][k][j]+4;
if(idade[13][k][j]>30)overallMax[13][k][j]=overall[13][k][j]+2;
}}
			
//termina de formatar colocando espaços	nos nomes		
for (var_n_ligas=0;var_n_ligas<n_ligas;var_n_ligas++){ 
for(k=1; k<=n_times;k++){
		for(j=1; j<n_posicoes;j++){
		for (posicao = 0; posicao<20;  posicao++) {if(jog[var_n_ligas][k][j][posicao]==NULL) {jog[var_n_ligas][k][j][posicao]=' ';} }
		    } }     }			



///////////////////////////////////////////////////////////////////////////////////////////////////////////

status[3]=0;
//Pontos dos times começa em 0
for(y=0;y<=n_ligas;y++){for(x=1;x<=n_times;x++){pts[y][x]=0;p_cres[y][x]=0;}}

//poe os jogadores mais fortes por posicao no clube	
			for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){
    	    for(x=1;x<=n_times;x++){
            for(y=1;y<=11;y++){
			i=1;	
			while(i<5){	i++;							 
			for(z=y;z<=n_posicoes;z++){k=0;
				if((y==1)        && strcmp("GOL",position[var_n_ligas][x][z])==0)k=1;
				if((y==2)        && strcmp("LAT",position[var_n_ligas][x][z])==0)k=1;
				if((y==3 || y==4)&& strcmp("ZAG",position[var_n_ligas][x][z])==0)k=1;
				if((y==5)        && strcmp("LAT",position[var_n_ligas][x][z])==0)k=1;
				if((y==6 || y==7)&& strcmp("VOL",position[var_n_ligas][x][z])==0)k=1;	
				if((y==8 || y==9)&& strcmp("MEI",position[var_n_ligas][x][z])==0)k=1;
				if((y==10||y==11)&& strcmp("ATA",position[var_n_ligas][x][z])==0)k=1;		
								
						if((overall[var_n_ligas][x][y]<overall[var_n_ligas][x][z] && k==1) || (strcmp(position[var_n_ligas][x][y],position[var_n_ligas][x][z])!=0 && k==1)){
						//	printf("%d-%s %s ",y,jog[var_n_ligas][x][y],jog[var_n_ligas][x][z]);getch();
				   						strcpy(auxiliar,jog[var_n_ligas][x][y]);strcpy(jog[var_n_ligas][x][y],jog[var_n_ligas][x][z]);strcpy(jog[var_n_ligas][x][z],auxiliar);
										auxiliar_int=idade[var_n_ligas][x][z];     idade[var_n_ligas][x][z]=idade[var_n_ligas][x][y];          idade[var_n_ligas][x][y]=auxiliar_int;
										auxiliar_int=overall[var_n_ligas][x][z];   overall[var_n_ligas][x][z]=overall[var_n_ligas][x][y];      overall[var_n_ligas][x][y]=auxiliar_int;
										auxiliar_int=overallMax[var_n_ligas][x][z];overallMax[var_n_ligas][x][z]=overallMax[var_n_ligas][x][y];overallMax[var_n_ligas][x][y]=auxiliar_int;
						  				auxiliar_int=amarelo[var_n_ligas][x][z];     amarelo[var_n_ligas][x][z]=amarelo[var_n_ligas][x][y];          amarelo[var_n_ligas][x][y]=auxiliar_int;
										auxiliar_int=vermelho[var_n_ligas][x][z];   vermelho[var_n_ligas][x][z]=vermelho[var_n_ligas][x][y];      vermelho[var_n_ligas][x][y]=auxiliar_int;
										auxiliar_int=machucado[var_n_ligas][x][z];machucado[var_n_ligas][x][z]=machucado[var_n_ligas][x][y];machucado[var_n_ligas][x][y]=auxiliar_int;
						  				auxiliar_int=jogados[var_n_ligas][x][z];jogados[var_n_ligas][x][z]=jogados[var_n_ligas][x][y];jogados[var_n_ligas][x][y]=auxiliar_int;
						  				strcpy(auxiliar,position[var_n_ligas][x][y]);strcpy(position[var_n_ligas][x][y],position[var_n_ligas][x][z]);strcpy(position[var_n_ligas][x][z],auxiliar);
						}									 
												}}}}}  

//************************************//     COMEÇO PROGRAMA    //*****************************************************************//   
//************************************//     COMEÇO PROGRAMA    //*****************************************************************//   
//************************************//     COMEÇO PROGRAMA    //*****************************************************************//    
j=0;
system("cls"); 	
textcolor(7,0);
printf("Escolha a Liga:\n");
for(x=1;x<n_ligas;x++){printf("(%d)%s\n",x,ntime[x][0]);}
while(j<=0 || j>=n_ligas){
						scanf("%d",&j);}
minha_liga=j;
if(j>=1 && j<n_ligas){
system("cls");  
printf("Escolha o seu time:\n");
         for(n=1;n<=n_times;n++){printf("(%d)%s\n",n,ntime[minha_liga][n]); }	
         while(timea<=0 || timea>n_times)
		 timea=getch()-48; 
		 //RANKING MINHA EQUIPE        
		for(y=1;y<=11;y++){rnk[minha_liga][timea]=rnk[minha_liga][timea]+overall[minha_liga][timea][y];}
		rnk[minha_liga][timea]=rnk[minha_liga][timea]/11;
		//GRANA INICIAL 
		 grana=(rnk[minha_liga][timea]-70)*(rnk[minha_liga][timea]-70)/2;
	}
	if(minha_liga>=8 && minha_liga<=13){champ_ou_liberta=1;} else {champ_ou_liberta=0;}
while(1){  
//ADVERSARIOS
if(campeonato==0){
	
              if(rodada==1){ chave1=3;chave2=1; chave3=6;chave4=4; chave5=8;chave6=5; chave7=7;chave8=2;}            
              if(rodada==2){ chave1=2;chave2=6; chave3=5;chave4=4; chave5=7;chave6=3; chave7=8;chave8=1;}
              if(rodada==3){ chave1=3;chave2=5; chave3=4;chave4=2; chave5=6;chave6=1; chave7=7;chave8=8;}
              if(rodada==4){ chave1=1;chave2=4; chave3=2;chave4=3; chave5=5;chave6=7; chave7=6;chave8=8;}
              if(rodada==5){ chave1=1;chave2=2; chave3=3;chave4=8; chave5=4;chave6=7; chave7=6;chave8=5;}
              if(rodada==6){ chave1=1;chave2=7; chave3=2;chave4=5; chave5=8;chave6=4; chave7=6;chave8=3;}
              if(rodada==7){ chave1=3;chave2=4; chave3=6;chave4=7; chave5=1;chave6=5; chave7=8;chave8=2;}
              
              if(rodada==8){ chave1=1;chave2=3; chave3=4;chave4=6; chave5=5;chave6=8; chave7=2;chave8=7;}
              if(rodada==9){ chave1=6;chave2=2; chave3=4;chave4=5;  chave5=3;chave6=7; chave7=1;chave8=8;}
              if(rodada==10){ chave1=5;chave2=3; chave3=2;chave4=4; chave5=1;chave6=6; chave7=8;chave8=7;}
              if(rodada==11){ chave1=4;chave2=1; chave3=3;chave4=2; chave5=7;chave6=5; chave7=8;chave8=6;}
              if(rodada==12){ chave1=2;chave2=1; chave3=8;chave4=3;  chave5=7;chave6=4; chave7=5;chave8=6;}
              if(rodada==13){ chave1=7;chave2=1; chave3=5;chave4=2; chave5=4;chave6=8; chave7=3;chave8=6;}
              if(rodada==14){ chave1=4;chave2=3; chave3=7;chave4=6; chave5=5;chave6=1; chave7=2;chave8=8;} 
if(timea==chave1)timeb=chave2;  if(timea==chave2)timeb=chave1; 
if(timea==chave3)timeb=chave4;  if(timea==chave4)timeb=chave3;          
if(timea==chave5)timeb=chave6;  if(timea==chave6)timeb=chave5;              
if(timea==chave7)timeb=chave8;  if(timea==chave8)timeb=chave7;              
      }
 //rodada da champions league  FASE de GRUPOS  
if(campeonato==1){          
			  if(fase==1){chave1=1;chave2=2; chave3=3;chave4=4;}
			  if(fase==2){chave1=3;chave2=1; chave3=4;chave4=2;}
			  if(fase==3){chave1=1;chave2=4; chave3=2;chave4=3;}
			  if(fase==4){chave1=2;chave2=1; chave3=4;chave4=3;}
			  if(fase==5){chave1=1;chave2=3; chave3=2;chave4=4;}
			  if(fase==6){chave1=4;chave2=1; chave3=3;chave4=2;}
			  
for(x=0;x<=15;x=x+4){if(meutimechampions==chave1+x)timeb=chave2+x;} 
for(x=0;x<=15;x=x+4){if(meutimechampions==chave2+x)timeb=chave1+x;} 
for(x=0;x<=15;x=x+4){if(meutimechampions==chave3+x)timeb=chave4+x;} 
for(x=0;x<=15;x=x+4){if(meutimechampions==chave4+x)timeb=chave3+x;} } 

if(campeonato==2){chave1=1;chave2=2; chave3=3;chave4=4; chave5=5;chave6=6; chave7=7;chave8=8;
			  			  if(meutimechampions==chave1)timeb=chave2;  if(meutimechampions==chave2)timeb=chave1; 
						  if(meutimechampions==chave3)timeb=chave4;  if(meutimechampions==chave4)timeb=chave3;
						  if(meutimechampions==chave5)timeb=chave6;  if(meutimechampions==chave6)timeb=chave5;              
						  if(meutimechampions==chave7)timeb=chave8;  if(meutimechampions==chave8)timeb=chave7; 
						  }  		
//poe os jogadores mais fortes por posicao no clube	
			for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){
    	    for(x=1;x<=n_times;x++){
    	    	if (var_n_ligas!=minha_liga || x!=timea){
            for(y=1;y<=11;y++){				  //y=posição de referencia
			for(z=y+1;z<=n_posicoes;z++){k=0; // z=posição procurada
				if((y==1)        && strcmp("GOL",position[var_n_ligas][x][z])==0)k=1;
				if((y==2)        && strcmp("LAT",position[var_n_ligas][x][z])==0)k=1;
				if((y==3 || y==4)&& strcmp("ZAG",position[var_n_ligas][x][z])==0)k=1;
				if((y==5)        && strcmp("LAT",position[var_n_ligas][x][z])==0)k=1;
				if((y==6 || y==7)&& strcmp("VOL",position[var_n_ligas][x][z])==0)k=1;	
				if((y==8 || y==9)&& strcmp("MEI",position[var_n_ligas][x][z])==0)k=1;
				if((y==10||y==11)&& strcmp("ATA",position[var_n_ligas][x][z])==0)k=1;		
								
						if(k==1 && ((overall[var_n_ligas][x][y]<overall[var_n_ligas][x][z] && machucado[var_n_ligas][x][z]==0 && vermelho[var_n_ligas][x][z]==0 && amarelo[var_n_ligas][x][z]<=2 ) || (machucado[var_n_ligas][x][y]>0 || vermelho[var_n_ligas][x][y]==1 || amarelo[var_n_ligas][x][y]>=3))
						        || (k==1 &&   (amarelo[var_n_ligas][x][y]==3 || vermelho[var_n_ligas][x][y]==1 || machucado[var_n_ligas][x][y]>0))
				   		){
				   						strcpy(auxiliar,jog[var_n_ligas][x][z]);strcpy(jog[var_n_ligas][x][z],jog[var_n_ligas][x][y]);strcpy(jog[var_n_ligas][x][y],auxiliar);
										auxiliar_int=idade[var_n_ligas][x][z];     idade[var_n_ligas][x][z]=idade[var_n_ligas][x][y];          idade[var_n_ligas][x][y]=auxiliar_int;
										auxiliar_int=overall[var_n_ligas][x][z];   overall[var_n_ligas][x][z]=overall[var_n_ligas][x][y];      overall[var_n_ligas][x][y]=auxiliar_int;
										auxiliar_int=overallMax[var_n_ligas][x][z];overallMax[var_n_ligas][x][z]=overallMax[var_n_ligas][x][y];overallMax[var_n_ligas][x][y]=auxiliar_int;
						  				auxiliar_int=amarelo[var_n_ligas][x][z];amarelo[var_n_ligas][x][z]=amarelo[var_n_ligas][x][y];amarelo[var_n_ligas][x][y]=auxiliar_int;
								  	    auxiliar_int=vermelho[var_n_ligas][x][z];vermelho[var_n_ligas][x][z]=vermelho[var_n_ligas][x][y];vermelho[var_n_ligas][x][y]=auxiliar_int;
									    auxiliar_int=machucado[var_n_ligas][x][z];machucado[var_n_ligas][x][z]=machucado[var_n_ligas][x][y];machucado[var_n_ligas][x][y]=auxiliar_int;
									    auxiliar_int=jogados[var_n_ligas][x][z];jogados[var_n_ligas][x][z]=jogados[var_n_ligas][x][y];jogados[var_n_ligas][x][y]=auxiliar_int;
						   
						   
						   }									 
												}}
												}}} 
//RANKING E IDADE MEDIAS DAS EQUIPES         
for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){         
for(x=1;x<=n_times;x++){rnk[var_n_ligas][x]=0;idade_med=0;        
for(y=1;y<=11;y++){rnk[var_n_ligas][x]=rnk[var_n_ligas][x]+overall[var_n_ligas][x][y];
                   idade_med=idade_med+idade[minha_liga][timea][y];
				   }//idad das equipes
rnk[var_n_ligas][x]=rnk[var_n_ligas][x]/11;//rnk das equipes 
idade_med=idade_med/11;
}}  
//*********************************************//       MENU PRINCIPAL    //******************************************************//
//*********************************************//       MENU PRINCIPAL    //******************************************************//
//*********************************************//       MENU PRINCIPAL    //******************************************************//
//*********************************************//       MENU PRINCIPAL    //******************************************************//    
//*********************************************//       MENU PRINCIPAL    //******************************************************//
system("cls");  
preco_jogador();
float soma_precos=0;
for(x=0;x<n_posicoes;x++){soma_precos=preco[minha_liga][timea][x]+soma_precos;}
float Valor_elenco = soma_precos;
for(x=11;x<n_posicoes;x++){soma_precos=preco[minha_liga][timea][x]+soma_precos;}
soma_precos=soma_precos/25;
printf("Ano: %d\n",ano);
tabela(ntime[minha_liga][timea]);printf("%s    ",ntime[minha_liga][timea]);
textcolor(2,0);printf(" Dinheiro:R$%.3f\n",grana);textcolor(7,0);
    printf("Valor do Elenco:    $%.2f\nPontuacao da Equipe:%.2f\n",Valor_elenco,rnk[minha_liga][timea]);
	printf("Idade da Equipe:    %.2f\n",idade_med);
    printf("Contratos:          %d jogos\n\n",contrato);
    printf("(1)Simular Partida\n");
    printf("(2)Tabela\n");
    printf("(3)Transferencias\n");
    printf("(4)Minha Equipe\n");
    printf("(5)Campeoes\n");
    printf("(6)Mudar de Time\n");
    printf("(7)Metas\n\n");
    printf("(A)Renovar contrato +10jogos  $%.2f\n",soma_precos);
    printf("(S)Simular");	
    if(SIMULACAO>=1){op=1;SIMULACAO--;}    
    else{op=getch()-48;}
    _sleep(10);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
if(op=='s'-48){printf("\n\n  Quantos jogos? ");
scanf("%d",&SIMULACAO);}
    system("cls");  
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		       
//faz o ranking	 na fase de champions 
if (campeonato>=1){
	         for(y=1;y<=16;y++){
              for(var_n_ligas=1;var_n_ligas<=n_ligas;var_n_ligas++){
             for(x=1;x<=n_times;x++){
                   if(strcmp(ntime[var_n_ligas][x],champions[y])==0)rnk[0][y]=rnk[var_n_ligas][x];}}}}
				   	
//Faz tabela de artilheiros do ano
		i=1;k=1;
       for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){
		    for(x=1;x<=n_times;x++){
            for(y=1;y<n_posicoes;y++){
					                            gols_cres[ano-ano_inicial][i]=gols[var_n_ligas][x][y];strcpy(artilheiro[ano-ano_inicial][i],jog[var_n_ligas][x][y]);i++;
				if(var_n_ligas==minha_liga){gols_cres_liga[ano-ano_inicial][k]=gols[var_n_ligas][x][y];strcpy(artilheiro_liga[ano-ano_inicial][k],jog[var_n_ligas][x][y]);k++;}
					}}}
            for(i=1;i<n_posicoes*n_times*n_ligas;i++){
                	for( x=i+1; x<n_posicoes*n_times*n_ligas; x++ ){
            if(gols_cres[ano-ano_inicial][i]<gols_cres[ano-ano_inicial][x]){
            	auxiliar_int=gols_cres[ano-ano_inicial][i];gols_cres[ano-ano_inicial][i]=gols_cres[ano-ano_inicial][x];gols_cres[ano-ano_inicial][x]=auxiliar_int;
            	strcpy(auxiliar,artilheiro[ano-ano_inicial][i]);strcpy(artilheiro[ano-ano_inicial][i],artilheiro[ano-ano_inicial][x]);strcpy(artilheiro[ano-ano_inicial][x],auxiliar);
																			} 
		                                            }}
		    for(i=1;i<n_posicoes*n_times;i++){
                	for( x=i+1; x<n_posicoes*n_times*n_ligas; x++ ){
            if(gols_cres_liga[ano-ano_inicial][i]<gols_cres_liga[ano-ano_inicial][x]){
								auxiliar_int=gols_cres_liga[ano-ano_inicial][i];gols_cres_liga[ano-ano_inicial][i]=gols_cres_liga[ano-ano_inicial][x];gols_cres_liga[ano-ano_inicial][x]=auxiliar_int;
            					strcpy(auxiliar,artilheiro_liga[ano-ano_inicial][i]);strcpy(artilheiro_liga[ano-ano_inicial][i],artilheiro_liga[ano-ano_inicial][x]);strcpy(artilheiro_liga[ano-ano_inicial][x],auxiliar);
      	   	    															} 
		                                            }}                                        
		                                               
//organiza a tabela em ordem	   
if (campeonato==0 || fase==1){      
	         for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){for(i=1;i<=n_times;i++){p_cres[var_n_ligas][i]=pts[var_n_ligas][i];strcpy(ntime_cres[var_n_ligas][i],ntime[var_n_ligas][i]);rnk_cres[var_n_ligas][i]=rnk[var_n_ligas][i];gols_feitos_cres[var_n_ligas][i]=gols_feitos[var_n_ligas][i];gols_tomados_cres[var_n_ligas][i]=gols_tomados[var_n_ligas][i];}
                 for(i=1;i<=n_times;i++){
                	for( x=i+1; x<=n_times; x++ ){
                      if(p_cres[var_n_ligas][i]<p_cres[var_n_ligas][x]){auxiliar_int=p_cres[var_n_ligas][i];p_cres[var_n_ligas][i]=p_cres[var_n_ligas][x];p_cres[var_n_ligas][x]=auxiliar_int;
                                 strcpy(auxiliar,ntime_cres[var_n_ligas][i]);strcpy(ntime_cres[var_n_ligas][i],ntime_cres[var_n_ligas][x]);strcpy(ntime_cres[var_n_ligas][x],auxiliar);
                  	             auxiliar_float=rnk_cres[var_n_ligas][i];rnk_cres[var_n_ligas][i]=rnk_cres[var_n_ligas][x];rnk_cres[var_n_ligas][x]=auxiliar_float;
                  	             auxiliar_int=gols_feitos_cres[var_n_ligas][i];gols_feitos_cres[var_n_ligas][i]=gols_feitos_cres[var_n_ligas][x];gols_feitos_cres[var_n_ligas][x]=auxiliar_int;
                  	             auxiliar_int=gols_tomados_cres[var_n_ligas][i];gols_tomados_cres[var_n_ligas][i]=gols_tomados_cres[var_n_ligas][x];gols_tomados_cres[var_n_ligas][x]=auxiliar_int;
						}       }}}
}
if (campeonato==1){  z=1;
    for(y=1;y<=4;y++){
	for(i=z;i<=z+3;i++){p_cres[0][i]=pts[0][i];rnk_cres[0][i]=rnk[0][i];strcpy(ntime_cres[0][i],champions[i]);
    for( x=z; x<=i; x++ ){
    if(p_cres[0][i]>p_cres[0][x]){auxiliar_int=p_cres[0][i];p_cres[0][i]=p_cres[0][x];p_cres[0][x]=auxiliar_int;
   								  auxiliar_float=rnk_cres[0][i];rnk_cres[0][i]=rnk_cres[0][x];rnk_cres[0][x]=auxiliar_float;
                                  strcpy(auxiliar,ntime_cres[0][i]);strcpy(ntime_cres[0][i],ntime_cres[0][x]);strcpy(ntime_cres[0][x],auxiliar);
                  	  }  }}z=z+4;  }
}                  	  
	
var_n_ligas=j;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int proibido=0;
if(contrato==0 && (grana>=soma_precos)){grana=grana-soma_precos;contrato=contrato+10;}
if(op==1 && contrato==0){printf("RENOVE OS CONTRATOS!!!");_sleep(1000); }
if(op==1 && FALTAS==1 && SIMULACAO==0){ 			proibido=0;
            for(x=2;x<=11;x++){if(vermelho[minha_liga][timea][x]==1){proibido=1;printf("Jogador com vermelho:%s \n",jog[minha_liga][timea][x]);			}
            		    		if(amarelo[minha_liga][timea][x]==3){proibido=1;printf("Jogador com 3 amarelos:%s \n",jog[minha_liga][timea][x]);			}	
								if(machucado[minha_liga][timea][x]>=1){proibido=1;printf("Jogador machucado:%s \n",jog[minha_liga][timea][x]);		}
								}}
if(proibido==1){getch();}//pausa depois da mensagem de jogador indisponivel pra jogar						
if(op==1 && contrato>0 && proibido==0){

	//Na champions League mostra os outros jogos
           if (campeonato==1){		printf("CHAMPIONS LEAGUE - ");  printf("RODADA %d\n\n",fase);			
					for(x=0;x<=15;x=x+4){
					   printf("%s - %s\n",champions[chave1+x],champions[chave2+x]);
					   printf("%s - %s\n",champions[chave3+x],champions[chave4+x]);}		 
                           		if(SIMULACAO<1){getch();}system("cls");  }
                             
          if (campeonato==2){printf("CHAMPIONS LEAGUE\n");
          					if(fase==7)printf("Quartas de final\n");
          					if(fase==8)printf("Semifinal\n");
          					if(fase==9)printf("Final\n");
                             }  
			  
//SIMULAÇÃO DO MEU JOGO
if(campeonato==0 || meutimechampions!=0){    

if(campeonato==0){ligab=minha_liga;time_adv=timeb; liga=minha_liga;
					printf("RODADA %d",rodada);
					}
if(campeonato>=1){  
					for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){         
					 for(x=1;x<=n_times;x++){   
                   if(strcmp(ntime[var_n_ligas][x],champions[timeb])==0) {time_adv=x; ligab=var_n_ligas;	  }     }}
						if(fase<=6)printf("RODADA %d",fase);
					}				
						
resul=rnk[minha_liga][timea]-rnk[ligab][time_adv];					
simula_jogo(); score=rand()%100;
if(minha_liga>=8 && minha_liga<=13)champ_ou_liberta=1;
if(campeonato==1){n=timea;timea=meutimechampions;liga=0;}//os parametros do pts[0][1-16] sao diferentes pts[minha_liga][1-8] 

if (campeonato<=1){				               
			
         if(score<vitoria){pts[liga][timea]=pts[liga][timea]+3;status[3]++;simula_gols(1,1,minha_liga,ligab,timea,time_adv);
         		if(campeonato==0){
         					if(liga==3){grana=grana+4.5;}
		                    if(liga<6 && liga!=3){grana=grana+4;}
							if(liga==6 || liga ==7  || liga==14){grana=grana+3;}
							if(liga==8){grana=grana+2.5;}
							if(liga==9 || liga==10){grana=grana+2.2;}
							if(liga>=11 && liga<=13){grana=grana+1.8;}
						}
							if(campeonato==1){if(champ_ou_liberta==1) grana=grana+3;
											  else grana=grana+6;}}
         if(score>=vitoria && score<=empate){pts[liga][timea]++;pts[liga][timeb]++;
		 								if((liga<=7  || liga==14) && campeonato==0){grana=grana+1.75;}
		 								if((liga>=8 && liga<=10) && campeonato==0){grana=grana+1.25;}
		 								if(liga>=11 && liga<=13 && campeonato==0){grana=grana+1;}
		 								if(campeonato==1)grana=grana+2.5;
		 									simula_gols(2,1,minha_liga,ligab,timea,time_adv);}
         if(score>empate){pts[liga][timeb]=pts[liga][timeb]+3;invicto=0;grana=grana+0.5;
		 					if(campeonato==1)grana+=1.25;simula_gols(3,1,minha_liga,ligab,timea,time_adv);} 

				}
if(campeonato==1){timea=n;}
						 				
if (campeonato==2){
					if(score<vitoria){vitoria_champions=1;simula_gols(1,1,minha_liga,ligab,timea,time_adv);} 
                    if(score>=vitoria){vitoria_champions=0;simula_gols(3,1,minha_liga,ligab,timea,time_adv);}							
              	 }			
			textcolor(15,2);
          printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		    printf("-                                                             -                                                     -\n");
		    printf("-                                                             -                                                     -\n");
		    printf("-                 %s                        -                           %s      -\n",jog[minha_liga][timea][2],jog[ligab][time_adv][2]);
			printf("-                                                             -                                                     -\n");
		    printf("-                                                             -                                                     -\n");
		    printf("-                                 %s        -       %s                          -\n",jog[minha_liga][timea][9],jog[ligab][time_adv][9]);
			printf("---------------                                               -                                     -----------------\n");
		    printf("-             -          %s                 -               %s  -               -\n",jog[minha_liga][timea][6],jog[ligab][time_adv][6]);
		    printf("-             -                                               -                                     -               -\n");
			printf("-             - %s                          -                          %s       -\n",jog[minha_liga][timea][3],jog[ligab][time_adv][3]);
		    printf("-             --                         %s -  %s              --               -\n",jog[minha_liga][timea][10],jog[ligab][time_adv][10]);
		    printf("-             - -                                             -                                   - -               -\n");
		    printf("-%s                                         -                                  %s\n",jog[minha_liga][timea][1],jog[ligab][time_adv][1]);
			printf("-             - -                                             -                                   - -               -\n");
		    printf("-             --                         %s -  %s              --               -\n",jog[minha_liga][timea][11],jog[ligab][time_adv][11]);
		    printf("-             - %s                          -                          %s       -\n",jog[minha_liga][timea][4],jog[ligab][time_adv][4]);
		    printf("-             -                                               -                                     -               -\n");
		    printf("-             -          %s                 -               %s  -               -\n",jog[minha_liga][timea][7],jog[ligab][time_adv][7]);		    
		    printf("---------------                                               -                                     -----------------\n");
		    printf("-                                 %s        -       %s                          -\n",jog[minha_liga][timea][8],jog[ligab][time_adv][8]);
		    printf("-                                                             -                                                     -\n");
		    printf("-                                                             -                                                     -\n");
		    printf("-                 %s                        -                           %s      -\n",jog[minha_liga][timea][5],jog[ligab][time_adv][5]);
		    printf("-                                                             -                                                     -\n");
		    printf("-                                                             -                                                     -\n");
		    printf("---------------------------------------------------------------------------------------------------------------------\n");
			textcolor(7,0);	
			 //reseta cartoes e lesoes
	        for(x=2;x<=n_posicoes;x++){if(vermelho[minha_liga][timea][x]==1)vermelho[minha_liga][timea][x]=0;if(amarelo[minha_liga][timea][x]==3)amarelo[minha_liga][timea][x]=0;	if(machucado[minha_liga][timea][x]>=1)machucado[minha_liga][timea][x]--;
									   if(vermelho[ligab][time_adv][x]==1)vermelho[ligab][time_adv][x]=0;if(amarelo[ligab][time_adv][x]==3)amarelo[ligab][time_adv][x]=0;	if(machucado[ligab][time_adv][x]>=1)machucado[ligab][time_adv][x]--;}
			//jogos jogados por cada jogador ->goleiro
			 for(x=1;x<=11;x++){jogados[minha_liga][timea][x]++; jogados[ligab][time_adv][x]++;}
			 for(x=2;x<=11;x++){			 
			 variavel=rand()%80-78;if(variavel<=0)variavel=0; vermelho[minha_liga][timea][x]+=variavel;
			 variavel=rand()%80-78;if(variavel<=0)variavel=0; vermelho[ligab][time_adv][x]+=variavel;
			 variavel=rand()%70-68;if(variavel<=0)variavel=0; else{variavel=rand()%12;} machucado[minha_liga][timea][x]+=variavel;
			 variavel=rand()%70-68;if(variavel<=0)variavel=0; else{variavel=rand()%12;} machucado[ligab][time_adv][x]+=variavel;
			 auxiliar[x]=rand()%5-3;  if(auxiliar[x]<=0)auxiliar[x]=0; amarelo[ligab][time_adv][x]+=auxiliar[x];
			 auxiliar[x]=rand()%5-3;  if(auxiliar[x]<=0)auxiliar[x]=0; amarelo[minha_liga][timea][x]+=auxiliar[x];
			 } 
			  printf("              RESERVAS");                printf("                     AMARELO  : ");for(x=2;x<=6;x++){if(auxiliar[x]>=1)printf("%s",jog[minha_liga][timea][x]);}printf("\n");
              printf("%s - %s",jog[minha_liga][timea][12],jog[ligab][time_adv][12]);printf("AMARELO  : ");for(x=7;x<=11;x++){if(auxiliar[x]>=1)printf("%s",jog[minha_liga][timea][x]);}printf("\n");
              printf("%s - %s",jog[minha_liga][timea][13],jog[ligab][time_adv][13]);printf("VERMELHO : ");for(x=1;x<=11;x++){if(vermelho[minha_liga][timea][x]>=1)printf("%s",jog[minha_liga][timea][x]);}printf("\n");
              printf("%s - %s",jog[minha_liga][timea][14],jog[ligab][time_adv][14]);printf("MACHUCADO: ");for(x=1;x<=11;x++){if(machucado[minha_liga][timea][x]>=1)printf("%s",jog[minha_liga][timea][x]);}printf("\n");
              for(x=15;x<=18;x++){printf("%s - %s\n",jog[minha_liga][timea][x],jog[ligab][time_adv][x]);}
              contrato--;
	            if(SIMULACAO<1){getch();}
				system("cls");}

	
 
         
 //SE CAMPEONATO NACIONAL        
if (campeonato==0){rodada++;
    	for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){    	srand(time(NULL));    
    	//POR RNK DO TIME
       if(timea!=chave1 && timea!=chave2 || var_n_ligas!=minha_liga ){resul=rnk[var_n_ligas][chave1]-rnk[var_n_ligas][chave2];simula_jogo();score=rand()%100;if(score<=vitoria){pts[var_n_ligas][chave1]=pts[var_n_ligas][chave1]+3;simula_gols(1,0,var_n_ligas,var_n_ligas,chave1,chave2);}    if(score>vitoria && score<empate){pts[var_n_ligas][chave1]++;pts[var_n_ligas][chave2]++;simula_gols(2,0,var_n_ligas,var_n_ligas,chave1,chave2);}  if(score>=empate){pts[var_n_ligas][chave2]=pts[var_n_ligas][chave2]+3;simula_gols(3,0,var_n_ligas,var_n_ligas,chave1,chave2);}}
       if(timea!=chave3 && timea!=chave4 || var_n_ligas!=minha_liga ){resul=rnk[var_n_ligas][chave3]-rnk[var_n_ligas][chave4];simula_jogo();score=rand()%100;if(score<=vitoria){pts[var_n_ligas][chave3]=pts[var_n_ligas][chave3]+3;simula_gols(1,0,var_n_ligas,var_n_ligas,chave3,chave4);}    if(score>vitoria && score<empate){pts[var_n_ligas][chave3]++;pts[var_n_ligas][chave4]++;simula_gols(2,0,var_n_ligas,var_n_ligas,chave3,chave4);}  if(score>=empate){pts[var_n_ligas][chave4]=pts[var_n_ligas][chave4]+3;simula_gols(3,0,var_n_ligas,var_n_ligas,chave3,chave4);}}
	   if(timea!=chave5 && timea!=chave6 || var_n_ligas!=minha_liga ){resul=rnk[var_n_ligas][chave5]-rnk[var_n_ligas][chave6];simula_jogo();score=rand()%100;if(score<=vitoria){pts[var_n_ligas][chave5]=pts[var_n_ligas][chave5]+3;simula_gols(1,0,var_n_ligas,var_n_ligas,chave5,chave6);}    if(score>vitoria && score<empate){pts[var_n_ligas][chave5]++;pts[var_n_ligas][chave6]++;simula_gols(2,0,var_n_ligas,var_n_ligas,chave5,chave6);}  if(score>=empate){pts[var_n_ligas][chave6]=pts[var_n_ligas][chave6]+3;simula_gols(3,0,var_n_ligas,var_n_ligas,chave5,chave6);}}
	   if(timea!=chave7 && timea!=chave8 || var_n_ligas!=minha_liga ){resul=rnk[var_n_ligas][chave7]-rnk[var_n_ligas][chave8];simula_jogo();score=rand()%100;if(score<=vitoria){pts[var_n_ligas][chave7]=pts[var_n_ligas][chave7]+3;simula_gols(1,0,var_n_ligas,var_n_ligas,chave7,chave8);}    if(score>vitoria && score<empate){pts[var_n_ligas][chave7]++;pts[var_n_ligas][chave8]++;simula_gols(2,0,var_n_ligas,var_n_ligas,chave7,chave8);}  if(score>=empate){pts[var_n_ligas][chave8]=pts[var_n_ligas][chave8]+3;simula_gols(3,0,var_n_ligas,var_n_ligas,chave7,chave8);}}   
}}

//SIMULA RODADA CHAMPIONS LEAGUE
if (campeonato==1 && fase<=6){fase++;
    	for(y=0;y<=15;y=y+4){     
       if(meutimechampions!=chave1+y && meutimechampions!=chave2+y){
	   			resul=rnk[0][chave1+y]-rnk[0][chave2+y];
				   simula_jogo();score=rand()%100;
	   			busca_time(chave1+y,chave2+y);
				   		if(score<=vitoria){pts[0][chave1+y]=pts[0][chave1+y]+3;simula_gols(1,0,liga1,liga2,time1,time2);}    if(score>vitoria && score<empate){pts[0][chave1+y]++;pts[0][chave2+y]++;simula_gols(2,0,liga1,liga2,time1,time2);}  if(score>=empate){pts[0][chave2+y]=pts[0][chave2+y]+3;simula_gols(3,0,liga1,liga2,time1,time2);}}
      
	   if(meutimechampions!=chave3+y && meutimechampions!=chave4+y){
	   			resul=rnk[0][chave3+y]-rnk[0][chave4+y];simula_jogo();score=rand()%100;     
				busca_time(chave3+y,chave4+y);
				   		if(score<=vitoria){pts[0][chave3+y]=pts[0][chave3+y]+3;simula_gols(1,0,liga1,liga2,time1,time2);}    if(score>vitoria && score<empate){pts[0][chave3+y]++;pts[0][chave4+y]++;simula_gols(2,0,liga1,liga2,time1,time2);}  if(score>=empate){pts[0][chave4+y]=pts[0][chave4+y]+3;simula_gols(3,0,liga1,liga2,time1,time2);}}
	 }	
	  if(SIMULACAO<1){getch();}
	 						}	 

//MATA MATA CHAMPIONS LEAGUE
if (campeonato==2){fase++;}
	
   if (fase==7){campeonato=2;
   //organiza a rodada da 6ªrodada
     z=1;
    for(y=1;y<=4;y++){
	for(i=z;i<=z+3;i++){p_cres[0][i]=pts[0][i];rnk_cres[0][i]=rnk[0][i];strcpy(ntime_cres[0][i],champions[i]);
    for( x=z; x<=i; x++ ){
    if(p_cres[0][i]>p_cres[0][x]){auxiliar_int=p_cres[0][i];p_cres[0][i]=p_cres[0][x];p_cres[0][x]=auxiliar_int;
   								  auxiliar_float=rnk_cres[0][i];rnk_cres[0][i]=rnk_cres[0][x];rnk_cres[0][x]=auxiliar_float;
                                  strcpy(auxiliar,ntime_cres[0][i]);strcpy(ntime_cres[0][i],ntime_cres[0][x]);strcpy(ntime_cres[0][x],auxiliar);
                  	  }  }}z=z+4;  }   
   
   strcpy(champions[1],ntime_cres[0][1]);
   strcpy(champions[2],ntime_cres[0][6]);
   strcpy(champions[3],ntime_cres[0][2]);
   strcpy(champions[4],ntime_cres[0][5]);
   strcpy(champions[5],ntime_cres[0][9]);
   strcpy(champions[6],ntime_cres[0][14]);
   strcpy(champions[7],ntime_cres[0][10]);
   strcpy(champions[8],ntime_cres[0][13]);
   }
   
   
  if (fase==8){
    if((meutimechampions==1 || meutimechampions==2) && vitoria_champions==1)	{if(champ_ou_liberta==0)grana=grana+20;else grana=grana+5; strcpy(champions[1],champions[meutimechampions]);}//Se ganhar nas quartas	
     if((meutimechampions==1 || meutimechampions==2) && vitoria_champions==0)	{if(champ_ou_liberta==0)grana=grana+10;else grana=grana+3;strcpy(champions[1],champions[timeb]);}//Se perder nas quartas
   	 if(meutimechampions!=1 && meutimechampions!=2){resul=rnk[0][chave1]-rnk[0][chave2];simula_jogo();
                 busca_time(1,2);
	   score=rand()%100;if(score<vitoria){strcpy(champions[1],champions[1]);simula_gols(1,0,liga1,liga2,time1,time2);}  if(score>=vitoria){strcpy(champions[1],champions[2]);simula_gols(3,0,liga1,liga2,time1,time2);}}
	   	
   if((meutimechampions==3 || meutimechampions==4) && vitoria_champions==1)	{if(champ_ou_liberta==0)grana=grana+20;else grana=grana+5;strcpy(champions[2],champions[meutimechampions]);}	
	 if((meutimechampions==3 || meutimechampions==4) && vitoria_champions==0)	{if(champ_ou_liberta==0)grana=grana+10;else grana=grana+3;strcpy(champions[2],champions[timeb]);}
	 if(meutimechampions!=3 && meutimechampions!=4){resul=rnk[0][chave3]-rnk[0][chave4];simula_jogo();
			busca_time(3,4);
	 score=rand()%100;if(score<vitoria){strcpy(champions[2],champions[3]);simula_gols(1,0,liga1,liga2,time1,time2);}  if(score>=vitoria){strcpy(champions[2],champions[4]);simula_gols(3,0,liga1,liga2,time1,time2);}}
	if((meutimechampions==5 || meutimechampions==6) && vitoria_champions==1)	{if(champ_ou_liberta==0)grana=grana+20;else grana=grana+5;strcpy(champions[3],champions[meutimechampions]);}	
	 if((meutimechampions==5 || meutimechampions==6) && vitoria_champions==0)	{if(champ_ou_liberta==0)grana=grana+10;else grana=grana+3;strcpy(champions[3],champions[timeb]);}
   	 if(meutimechampions!=5 && meutimechampions!=6){resul=rnk[0][chave5]-rnk[0][chave6];simula_jogo();
   	 	 	busca_time(5,6);
    	score=rand()%100;if(score<vitoria){strcpy(champions[3],champions[5]);simula_gols(1,0,liga1,liga2,time1,time2);}  if(score>=vitoria){strcpy(champions[3],champions[6]);simula_gols(3,0,liga1,liga2,time1,time2);}}
	 if((meutimechampions==7 || meutimechampions==8) && vitoria_champions==1)	{if(champ_ou_liberta==0)grana=grana+20;else grana=grana+5;strcpy(champions[4],champions[meutimechampions]);}
	 if((meutimechampions==7 || meutimechampions==8) && vitoria_champions==0)	{if(champ_ou_liberta==0)grana=grana+10;else grana=grana+3;strcpy(champions[4],champions[timeb]);}
	if(meutimechampions!=7 && meutimechampions!=8){resul=rnk[0][chave7]-rnk[0][chave8];simula_jogo();
	   		busca_time(7,8);
	score=rand()%100;if(score<vitoria){strcpy(champions[4],champions[7]);simula_gols(1,0,liga1,liga2,time1,time2);}  if(score>=vitoria){strcpy(champions[4],champions[8]);simula_gols(3,0,liga1,liga2,time1,time2);}}
          printf("\n\nCLASSIFICADOS:%s %s %s %s",champions[1],champions[2],champions[3],champions[4]);
		  }
  if (fase==9){
  	 if((meutimechampions==1 || meutimechampions==2) && vitoria_champions==1)	{if(champ_ou_liberta==0)grana=grana+30;else grana=grana+7;strcpy(champions[1],champions[meutimechampions]);strcpy(terceiro[ano-ano_inicial],champions[timeb]);}	
     if((meutimechampions==1 || meutimechampions==2) && vitoria_champions==0)	{if(champ_ou_liberta==0)grana=grana+15;else grana=grana+4;strcpy(champions[1],champions[timeb]);strcpy(terceiro[ano-ano_inicial],champions[meutimechampions]);}
   	if(meutimechampions!=1 && meutimechampions!=2){resul=rnk[0][chave1]-rnk[0][chave2];simula_jogo();busca_time(1,2);
   	//champions[5] utilizado para nao seobrescrever variavel champions 1
       strcpy(champions[5],champions[1]);
	   score=rand()%100;if(score<vitoria){ strcpy(terceiro[ano-ano_inicial],champions[2]);                                  simula_gols(1,0,liga1,liga2,time1,time2);}  
	   					if(score>=vitoria){strcpy(terceiro[ano-ano_inicial],champions[1]);strcpy(champions[1],champions[2]);simula_gols(3,0,liga1,liga2,time1,time2);}}
	 
	 if((meutimechampions==3 || meutimechampions==4) && vitoria_champions==1)	{if(champ_ou_liberta==0)grana=grana+30;else grana=grana+7;strcpy(champions[2],champions[meutimechampions]);strcpy(quarto[ano-ano_inicial],champions[timeb]);}	
	 if((meutimechampions==3 || meutimechampions==4) && vitoria_champions==0)	{if(champ_ou_liberta==0)grana=grana+15;else grana=grana+4;strcpy(champions[2],champions[timeb]);           strcpy(quarto[ano-ano_inicial],champions[meutimechampions]);}
    if(meutimechampions!=3 && meutimechampions!=4){resul=rnk[0][chave3]-rnk[0][chave4];simula_jogo();busca_time(3,4);
	score=rand()%100;if(score<vitoria){strcpy(quarto[ano-ano_inicial],champions[4]);strcpy(champions[2],champions[3]);simula_gols(1,0,liga1,liga2,time1,time2);}  
					 if(score>=vitoria){strcpy(quarto[ano-ano_inicial],champions[3]);strcpy(champions[2],champions[4]);simula_gols(3,0,liga1,liga2,time1,time2);}}
	      printf("\n\nCLASSIFICADOS:%s %s",champions[1],champions[2]);
		  }
  if (fase==10){
  	if((meutimechampions==1 || meutimechampions==2) && vitoria_champions==1)	{ //Campeão Internacional
  																	Beep(700,300);Beep(600,300);Beep(800,700);
	  																strcpy(campeao[ano-ano_inicial],champions[meutimechampions]);strcpy(vice[ano-ano_inicial],champions[timeb]);status[2]=1;if(champ_ou_liberta==0)grana=grana+40;else grana=grana+10;}//CAMPEAO GANHA 80 MILHOES	
    if((meutimechampions==1 || meutimechampions==2) && vitoria_champions==0)	{strcpy(campeao[ano-ano_inicial],champions[timeb]);strcpy(vice[ano-ano_inicial],champions[meutimechampions]);if(champ_ou_liberta==0)grana=grana+15;else grana=grana+5;}
  	if(meutimechampions!=1 && meutimechampions!=2){score=rand()%2;busca_time(1,2);   //50% de chances de ser campeao
	  															if(score==0){strcpy(campeao[ano-ano_inicial],champions[1]);strcpy(vice[ano-ano_inicial],champions[2]);simula_gols(1,0,liga1,liga2,time1,time2);} 
	  															 if(score==1){strcpy(campeao[ano-ano_inicial],champions[2]);strcpy(vice[ano-ano_inicial],champions[1]);simula_gols(3,0,liga1,liga2,time1,time2);}}
	  if(champ_ou_liberta==0)printf("\n\nCAMPEAO DA CHAMPIONS LEAGUE %d: %s",ano,campeao[ano-ano_inicial]);
	  if(champ_ou_liberta==1)printf("\n\nCAMPEAO DA COPA LIBERTADORES %d: %s",ano,campeao[ano-ano_inicial]);
	  
	  				if(SIMULACAO<1){_sleep(1000);getch();}
	  final=1;fase=0;campeonato==0;meutimechampions=0;rodada=1;
	  }	
	if(fase>=8 && SIMULACAO<1){getch();}  
	 
//FIM DO CAMPEONATO Nacional
if (rodada==15){ campeonato=1; fase=1;rodada=1; 
for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){for(i=1;i<=n_times;i++){p_cres[var_n_ligas][i]=pts[var_n_ligas][i];strcpy(ntime_cres[var_n_ligas][i],ntime[var_n_ligas][i]);rnk_cres[var_n_ligas][i]=rnk[var_n_ligas][i];}
                 for(i=1;i<=n_times;i++){
                	for( x=i+1; x<=n_times; x++ ){
                      if(p_cres[var_n_ligas][i]<p_cres[var_n_ligas][x]){auxiliar_int=p_cres[var_n_ligas][i];p_cres[var_n_ligas][i]=p_cres[var_n_ligas][x];p_cres[var_n_ligas][x]=auxiliar_int;
                                 strcpy(auxiliar,ntime_cres[var_n_ligas][i]);strcpy(ntime_cres[var_n_ligas][i],ntime_cres[var_n_ligas][x]);strcpy(ntime_cres[var_n_ligas][x],auxiliar);
                  	             auxiliar_float=rnk_cres[var_n_ligas][i];rnk_cres[var_n_ligas][i]=rnk_cres[var_n_ligas][x];rnk_cres[var_n_ligas][x]=auxiliar_float;
						}       }}}
              system("cls");
              printf("CLASSIFICACAO FINAL:\n\n TIME             PTS\n");
	          for(x=1;x<=8;x++){printf("%d-%s %d   %.1f\n",x,ntime_cres[minha_liga][x],p_cres[minha_liga][x],rnk_cres[minha_liga][x]);
			                    if(strcmp(ntime[minha_liga][timea],ntime_cres[minha_liga][x])==0){minha_posicao[ano-ano_inicial]=x;}}
                
			  if(strcmp(ntime[minha_liga][timea],ntime_cres[minha_liga][1])==0){printf("\n\nCAMPEAO NACIONAL!!!");status[1]=1;grana=grana+10;  }
			  	          if(invicto==1){status[5]=1;printf("\nTEMPORADA INVICTO\n");} invicto=1;
			  
			  if(SIMULACAO<1){getch();}
		 //LIMPA A PONTUAÇÃO DOS TIMES
		  for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){for(i=1;i<=n_times;i++){p_cres[0][i]=0;pts[0][i]=0;}} 
		  
                  	//CAMPEAO nacional[ano-ano_inicial][1] = salva nome do campeao nacional
		  				  for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){for(x=1;x<=n_times;x++){
							if(strcmp(ntime[var_n_ligas][x],ntime_cres[var_n_ligas][1])==0){strcpy(nacional[ano-ano_inicial][var_n_ligas],ntime_cres[var_n_ligas][1]); }}}
							
                         for(x=1;x<=n_times;x++){ 
                         if(minha_liga>=1 && minha_liga<=7 || minha_liga==14){
		                     if(strcmp(ntime[1][x],ntime_cres[1][1])==0){strcpy(champions[1],ntime_cres[1][1]);}
							 if(strcmp(ntime[1][x],ntime_cres[1][2])==0){strcpy(champions[2],ntime_cres[1][2]); } 
							 if(strcmp(ntime[1][x],ntime_cres[1][3])==0){strcpy(champions[3],ntime_cres[1][3]); }  //3 ESP
							 if(strcmp(ntime[2][x],ntime_cres[2][1])==0){strcpy(champions[4],ntime_cres[2][1]);}  
							 if(strcmp(ntime[2][x],ntime_cres[2][2])==0){strcpy(champions[5],ntime_cres[2][2]); } 
							 if(strcmp(ntime[2][x],ntime_cres[2][3])==0){strcpy(champions[6],ntime_cres[2][3]); }  //3 ITA
							 if(strcmp(ntime[3][x],ntime_cres[3][1])==0){strcpy(champions[7],ntime_cres[3][1]);} 
							 if(strcmp(ntime[3][x],ntime_cres[3][2])==0){strcpy(champions[8],ntime_cres[3][2]); } 
							 if(strcmp(ntime[3][x],ntime_cres[3][3])==0){strcpy(champions[9],ntime_cres[3][3]); }  //3ING
							 if(strcmp(ntime[3][x],ntime_cres[3][4])==0){strcpy(champions[10],ntime_cres[4][1]);}  
							 if(strcmp(ntime[4][x],ntime_cres[4][1])==0){strcpy(champions[11],ntime_cres[4][2]);}  //ALE
							 if(strcmp(ntime[4][x],ntime_cres[4][2])==0){strcpy(champions[12],ntime_cres[5][1]);}   
							 if(strcmp(ntime[5][x],ntime_cres[5][1])==0){strcpy(champions[13],ntime_cres[5][2]);} //FRA
							 if(strcmp(ntime[6][x],ntime_cres[6][1])==0){strcpy(champions[14],ntime_cres[6][1]); }  
							 if(strcmp(ntime[6][x],ntime_cres[6][2])==0){strcpy(champions[15],ntime_cres[6][2]);}  //Ocidental
							 if(strcmp(ntime[7][x],ntime_cres[7][1])==0){strcpy(champions[16],ntime_cres[7][1]);}  //Oriental
						}
						if(minha_liga>=8 && minha_liga<=13){	
						     if(strcmp(ntime[8][x],ntime_cres[8][1])==0){strcpy(champions[1],ntime_cres[8][1]);} //4 BRASIL
							 if(strcmp(ntime[8][x],ntime_cres[8][2])==0){strcpy(champions[2],ntime_cres[8][2]); } 
							 if(strcmp(ntime[8][x],ntime_cres[8][3])==0){strcpy(champions[3],ntime_cres[8][3]); } 
							 if(strcmp(ntime[8][x],ntime_cres[8][4])==0){strcpy(champions[4],ntime_cres[8][4]);}  
							 if(strcmp(ntime[11][x],ntime_cres[11][1])==0){strcpy(champions[5],ntime_cres[11][1]); }  //3 COL
							 if(strcmp(ntime[11][x],ntime_cres[11][2])==0){strcpy(champions[6],ntime_cres[11][2]); }  
							 if(strcmp(ntime[11][x],ntime_cres[11][3])==0){strcpy(champions[7],ntime_cres[11][3]);} 
							 if(strcmp(ntime[10][x],ntime_cres[10][1])==0){strcpy(champions[8],ntime_cres[10][1]); }  //4 ARGENTINA
							 if(strcmp(ntime[10][x],ntime_cres[10][2])==0){strcpy(champions[9],ntime_cres[10][2]);}  
							 if(strcmp(ntime[10][x],ntime_cres[10][3])==0){strcpy(champions[10],ntime_cres[10][3]);}  
							 if(strcmp(ntime[10][x],ntime_cres[10][4])==0){strcpy(champions[11],ntime_cres[10][4]);}							 
							 if(strcmp(ntime[12][x],ntime_cres[12][1])==0){strcpy(champions[12],ntime_cres[12][1]); } //3 SULAMERICA   
							 if(strcmp(ntime[12][x],ntime_cres[12][2])==0){strcpy(champions[13],ntime_cres[12][2]);}
							 if(strcmp(ntime[12][x],ntime_cres[12][3])==0){strcpy(champions[14],ntime_cres[12][3]); }  
							 if(strcmp(ntime[13][x],ntime_cres[13][1])==0){strcpy(champions[15],ntime_cres[13][1]);}  //2 PERU EQUADOR BOLIVIA
							 if(strcmp(ntime[13][x],ntime_cres[13][2])==0){strcpy(champions[16],ntime_cres[13][2]);}  
						}
							//Rebaixado
							if(n_ligas>=10){
								//Brasileirao
								  if(strcmp(ntime[8][x],ntime_cres[8][8])==0){rebaixado1=x; }
								  if(strcmp(ntime[9][x],ntime_cres[9][1])==0){acesso1=x; }
								  if(strcmp(ntime[8][x],ntime_cres[8][7])==0){rebaixado2=x; }
								  if(strcmp(ntime[9][x],ntime_cres[9][2])==0){acesso2=x; }
								  //Premier League
								  if(n_ligas>=14){
								  if(strcmp(ntime[3][x],ntime_cres[3][8])==0){rebaixado1b=x; }
								  if(strcmp(ntime[14][x],ntime_cres[14][1])==0){acesso1b=x; }
								  if(strcmp(ntime[3][x],ntime_cres[3][7])==0){rebaixado2b=x; }
								  if(strcmp(ntime[14][x],ntime_cres[14][2])==0){acesso2b=x; }              
								  		     		 }
									}
							 
				 } //fim loop n_times
							 
				 //para sortear os grupos da champions e lib ertadores
				 for(y=1;y<30;y++){n=rand()%16+1;x=rand()%16+1;strcpy(auxiliar,champions[n]);strcpy(champions[n],champions[x]);strcpy(champions[x],auxiliar);} 
				 for(y=1;y<30;y++){n=rand()%16+1;x=rand()%16+1;strcpy(auxiliar,libertadores[n]);strcpy(libertadores[n],libertadores[x]);strcpy(libertadores[x],auxiliar);} 
		}//Rodada 15
  
  
  
					
//se meu time estiver na champions league
    meutimechampions=0;if(fase<=6)n=16;if(fase==7)n=8;if(fase==8)n=4;if(fase==9)n=2;
	for(x=1;x<=n;x++){if(strcmp(ntime[minha_liga][timea],champions[x])==0)meutimechampions=x;
	                   if(meutimechampions>n)meutimechampions=0; }		   	
   
    if (final ==1){campeonato=0;rodada=1;ano++;final=0;system("cls");
    			int gol=0;//ve quem tem mais gols pra definir o artilheiro
    			int melhor_overall[5]; melhor_overall[1]=85;//define o overall do melhor do mundo
//LIMPA A PONTUAÇÃO DOS TIMES
		  for(var_n_ligas=0;var_n_ligas<n_ligas;var_n_ligas++){for(i=1;i<=20;i++){p_cres[var_n_ligas][i]=0;pts[var_n_ligas][i]=0;}}    	                   
    	   //atualiza overall dos jogadores e idade
    	    for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){
    	    for(x=1;x<=n_times;x++){
            for(y=1;y<n_posicoes;y++){
			
			//Artilheiros
			if(gols[var_n_ligas][x][y]>=gol){
			gol=gols[var_n_ligas][x][y];}
		
			
		//zera os gols
			gols[var_n_ligas][x][y]=0;
			gols_tomados[var_n_ligas][x]=0;
			gols_feitos[var_n_ligas][x]=0;
		//zera cartoes
		    amarelo[minha_liga][timea][y]=0;vermelho[minha_liga][timea][y]=0;
			
		//muda jogador quando se aposenta
			score=rand()%10;
			if(substituir>n_jovens-100){substituir=1;}
				if(idade[var_n_ligas][x][y]>=35 && score>=7){strcpy(jog[var_n_ligas][x][y],jovens[substituir]);substituir++;idade[var_n_ligas][x][y]=16+rand()%4;overallMax[var_n_ligas][x][y]=75+rand()%22;overall[var_n_ligas][x][y]=64+rand()%12;jogados[var_n_ligas][x][y]=0;	}
				if(idade[var_n_ligas][x][y]>=38 && score>=4){strcpy(jog[var_n_ligas][x][y],jovens[substituir]);substituir++;idade[var_n_ligas][x][y]=16+rand()%4;overallMax[var_n_ligas][x][y]=75+rand()%22;overall[var_n_ligas][x][y]=64+rand()%12;jogados[var_n_ligas][x][y]=0;	}
				if(idade[var_n_ligas][x][y]>=40 && score>=1){strcpy(jog[var_n_ligas][x][y],jovens[substituir]);substituir++;idade[var_n_ligas][x][y]=16+rand()%4;overallMax[var_n_ligas][x][y]=75+rand()%22;overall[var_n_ligas][x][y]=64+rand()%12;jogados[var_n_ligas][x][y]=0;	}
			    if(idade[var_n_ligas][x][y]==42){strcpy(jog[var_n_ligas][x][y],jovens[substituir]);substituir++;idade[var_n_ligas][x][y]=16+rand()%4;overallMax[var_n_ligas][x][y]=75+rand()%22;overall[var_n_ligas][x][y]=64+rand()%12;jogados[var_n_ligas][x][y]=0;	}
			
			  
			score=rand()%6;//mudança de overall aleatoria
				 if(idade[var_n_ligas][x][y]<20){score=rand()%5;}//0 a 4
				 if(idade[var_n_ligas][x][y]>=20&&idade[var_n_ligas][x][y]<24)score=rand()%5-1;//-1 a 3 
			     if(idade[var_n_ligas][x][y]>=24&&idade[var_n_ligas][x][y]<29)score=score-2;//-2 a 3 
			  	 if(idade[var_n_ligas][x][y]>=30&&idade[var_n_ligas][x][y]<34)score=score-3;//-3 a 2
				 if(idade[var_n_ligas][x][y]>=34)score=rand()%5-3;//-3 a 1				 
				 if(overall[var_n_ligas][x][y]>=89)score=rand()%3-1;
			  idade[var_n_ligas][x][y]++;
			  

			  if(x==timea && var_n_ligas==minha_liga){printf("%s(%d) %d",jog[minha_liga][x][y],idade[minha_liga][x][y],overall[minha_liga][x][y]);}
			  if(overall[var_n_ligas][x][y]+score>=overallMax[var_n_ligas][x][y]){overall[var_n_ligas][x][y]=overallMax[var_n_ligas][x][y];}
			  if(overall[var_n_ligas][x][y]+score<overallMax[var_n_ligas][x][y]){ overall[var_n_ligas][x][y]=overall[var_n_ligas][x][y]+score;}
			  if(x==timea && var_n_ligas==minha_liga){printf("->%d\n",overall[minha_liga][x][y]);}

		//Melhor do Mundo
		for(k=6;k>=1;k--){
				if(overall[var_n_ligas][x][y]>=melhor_overall[k] && y>=2){  //y>2 desconsidera o goleiro
				        	melhor_overall[k+1]=melhor_overall[k];
					        melhor_overall[k]=overall[var_n_ligas][x][y];
					        strcpy(melhor_mundo[ano-ano_inicial][k+1],melhor_mundo[ano-ano_inicial][k]);	
							strcpy(melhor_mundo[ano-ano_inicial][k],jog[var_n_ligas][x][y]);
							}}
			 //Transferencia entre os clubes
			 score=rand()%8;
			 if((x!=timea || var_n_ligas!=minha_liga) && score==0){
				
			 	i=1;
			 	n=400;
			 	while(i<n){
			 	 i++;
			 	 int b,c,d;
				  d=rand()%8;   b=rand()%n_times;	   c=rand()%n_posicoes;  //procura por jogadores aleatorios 300x
                if(var_n_ligas==8)if(i<n/2){d=8;}else{d=9;} //se for do campeonato brasileiro só troca com jogadores do brasil	
				if(var_n_ligas==9)if(i<n/2){d=8;}else{d=9;} //se for do campeonato brasileiro só troca com jogadores do brasil	
				if(var_n_ligas==10)d=10; //se for do campeonato argentino só troca com jogadores do argentino
				if(var_n_ligas==11)d=11; //se for do campeonato colombiano
				if(var_n_ligas==12)d=12; //se for do campeonato sul americano
				if(var_n_ligas==13)d=13; //se for do campeonato EQUADOR e PERU
			if((b!=timea || d!=minha_liga) ){			
			if(strcmp(position[var_n_ligas][x][y],position[d][b][c])==0){	//compara se é da mesma posicao
			if(preco[var_n_ligas][x][y]<=preco[d][b][c]*1.4 && preco[var_n_ligas][x][y]>=preco[d][b][c]*0.7){	//se preco for parecido
					i=n+100;						 
			strcpy(auxiliar,jog[var_n_ligas][x][y]);strcpy(jog[var_n_ligas][x][y],jog[d][b][c]);strcpy(jog[d][b][c],auxiliar);
			auxiliar_int=idade[d][b][c];     idade[d][b][c]=idade[var_n_ligas][x][y];          idade[var_n_ligas][x][y]=auxiliar_int;
			auxiliar_int=overall[d][b][c];   overall[d][b][c]=overall[var_n_ligas][x][y];      overall[var_n_ligas][x][y]=auxiliar_int;
			auxiliar_int=overallMax[d][b][c];overallMax[d][b][c]=overallMax[var_n_ligas][x][y];overallMax[var_n_ligas][x][y]=auxiliar_int;
													 }}}}}
			}}} 
			
			//poe os jogadores mais fortes por posicao no clube	
			for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){
    	    for(x=1;x<=n_times;x++){
            for(y=1;y<=11;y++){
			i=1;	
			while(i<5){	i++;							 
			for(z=12;z<=n_posicoes;z++){
			       if(strcmp(position[var_n_ligas][x][y],position[var_n_ligas][x][z])==0){	
				   		if(overall[var_n_ligas][x][y]<overall[var_n_ligas][x][z]){
				   						strcpy(auxiliar,jog[var_n_ligas][x][y]);strcpy(jog[var_n_ligas][x][y],jog[var_n_ligas][x][z]);strcpy(jog[var_n_ligas][x][z],auxiliar);
										auxiliar_int=idade[var_n_ligas][x][z];     idade[var_n_ligas][x][z]=idade[var_n_ligas][x][y];          idade[var_n_ligas][x][y]=auxiliar_int;
										auxiliar_int=overall[var_n_ligas][x][z];   overall[var_n_ligas][x][z]=overall[var_n_ligas][x][y];      overall[var_n_ligas][x][y]=auxiliar_int;
										auxiliar_int=overallMax[var_n_ligas][x][z];overallMax[var_n_ligas][x][z]=overallMax[var_n_ligas][x][y];overallMax[var_n_ligas][x][y]=auxiliar_int;
						   }									 
												}}}}}}
												
	
	//muda o time rebaixado pelo que subiu de divisao 
		auxiliar_int=0;
		//BR
		int SerieA = 8,SerieB = 9;
	for(x=1;x<=2;x++){	    
	if (x==1){int SerieA = 8,SerieB = 9;	} //BR
	if (x==2 && n_ligas>=14){SerieA = 3;SerieB = 14;	//ING
	rebaixado1 = rebaixado1b; rebaixado2 = rebaixado2b; acesso1 =acesso1b; acesso2=acesso2b;
	} //ING
	if (x==2 && n_ligas<14){SerieA = 1;SerieB = 1;}
		if(minha_liga == SerieA && timea == rebaixado1)				  {minha_liga=SerieB;j=SerieB;timea=acesso1;auxiliar_int=1;}//se for o meu time	
		if(minha_liga == SerieB && timea == acesso1 && auxiliar_int==0){minha_liga=SerieA;j=SerieA;timea=rebaixado1;}//se for o meu time	
		if(minha_liga == SerieA && timea == rebaixado2)				  {minha_liga=SerieB;j=SerieB;timea=acesso2;auxiliar_int=1;}//se for o meu time	
		if(minha_liga == SerieB && timea == acesso2 && auxiliar_int==0){minha_liga=SerieA;j=SerieA;timea=rebaixado2;}//se for o meu time	
						
						strcpy(auxiliar,ntime[SerieB][acesso1]);	strcpy(ntime[SerieB][acesso1],ntime[SerieA][rebaixado1]);strcpy(ntime[SerieA][rebaixado1],auxiliar);	
						strcpy(auxiliar,ntime[SerieB][acesso2]);	strcpy(ntime[SerieB][acesso2],ntime[SerieA][rebaixado2]);strcpy(ntime[SerieA][rebaixado2],auxiliar);	
		for(y=1;y<n_posicoes;y++){	
			strcpy(auxiliar,jog[SerieB][acesso1][y]);      strcpy(jog[SerieB][acesso1][y],jog[SerieA][rebaixado1][y]);          strcpy(jog[SerieA][rebaixado1][y],auxiliar);
			auxiliar_int=idade[SerieB][acesso1][y];        idade[SerieB][acesso1][y]=idade[SerieA][rebaixado1][y];              idade[SerieA][rebaixado1][y]=auxiliar_int;
			auxiliar_int=overall[SerieB][acesso1][y];      overall[SerieB][acesso1][y]=overall[SerieA][rebaixado1][y];          overall[SerieA][rebaixado1][y]=auxiliar_int;
			auxiliar_int=overallMax[SerieB][acesso1][y];   overallMax[SerieB][acesso1][y]=overallMax[SerieA][rebaixado1][y];    overallMax[SerieA][rebaixado1][y]=auxiliar_int;
			strcpy(auxiliar,position[SerieB][acesso1][y]); strcpy(position[SerieB][acesso1][y],position[SerieA][rebaixado1][y]);strcpy(position[SerieA][rebaixado1][y],auxiliar);
			
			strcpy(auxiliar,position[SerieB][acesso2][y]); strcpy(position[SerieB][acesso2][y],position[SerieA][rebaixado2][y]);strcpy(position[SerieA][rebaixado2][y],auxiliar);
			strcpy(auxiliar,jog[SerieB][acesso2][y]);      strcpy(jog[SerieB][acesso2][y],jog[SerieA][rebaixado2][y]);          strcpy(jog[SerieA][rebaixado2][y],auxiliar);
			auxiliar_int=idade[SerieB][acesso2][y];        idade[SerieB][acesso2][y]=idade[SerieA][rebaixado2][y];              idade[SerieA][rebaixado2][y]=auxiliar_int;
			auxiliar_int=overall[SerieB][acesso2][y];      overall[SerieB][acesso2][y]=overall[SerieA][rebaixado2][y];          overall[SerieA][rebaixado2][y]=auxiliar_int;
			auxiliar_int=overallMax[SerieB][acesso2][y];   overallMax[SerieB][acesso2][y]=overallMax[SerieA][rebaixado2][y];    overallMax[SerieA][rebaixado2][y]=auxiliar_int;
		}	
	}
      
	 		 printf("\nPontuacao da Equipe: %.2f -> ",rnk[minha_liga][timea]);	 
						rnk[minha_liga][timea]=0;       
						for(y=1;y<=11;y++){rnk[minha_liga][timea]=rnk[minha_liga][timea]+(overall[minha_liga][timea][y]); }
			 printf("%.2f",rnk[minha_liga][timea]/11);
			  float auxilia=Valor_elenco;Valor_elenco=0;preco_jogador();
			 for(x=0;x<n_posicoes;x++){Valor_elenco=preco[minha_liga][timea][x]+Valor_elenco;}             
			  printf("\nValor do Elenco: %.2f -> %.2f\n",auxilia,Valor_elenco);		
	
		printf("\n\nMelhor jogador do Mundo: %s %s %s\n\n",melhor_mundo[ano-ano_inicial][1],melhor_mundo[ano-ano_inicial][2],melhor_mundo[ano-ano_inicial][3]);
		printf("Artilheiro do Ano      : %s %d gols",artilheiro[ano-1-ano_inicial][1],gols_cres[ano-1-ano_inicial][1]);
		if(SIMULACAO<1){getch();}										
		}//FIM CHAMPIONS
	}
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if(op==2){   //MINHA LIGA E ARTILHEIROS
			  printf("SEMANA:%d   %s\n",rodada,ntime[minha_liga][0]);	
              printf(" TIME             PTS   GM GS                ARTILHEIRO DO ANO             ARTILHEIRO DA LIGA\n");
              minha_liga=j;
	          for(x=1;x<=8;x++){printf("%d-",x);tabela(ntime_cres[minha_liga][x]);printf("%s ",ntime_cres[minha_liga][x]);textcolor(7,0);printf(" %d ",p_cres[minha_liga][x]);
			  					if(p_cres[minha_liga][x]<10)printf(" ");printf("  %d",gols_feitos_cres[minha_liga][x]);if(gols_feitos_cres[minha_liga][x]<10)printf(" ");printf(" %d ",gols_tomados_cres[minha_liga][x]);if(gols_tomados_cres[minha_liga][x]<10)printf(" ");printf(" %.1f",rnk_cres[minha_liga][x]);if(gols_cres[ano-ano_inicial][x]<=0)printf("\n");if(gols_cres[ano-ano_inicial][x]>0)printf("          %d- %s %d     %d - %s %d\n",x,artilheiro[ano-ano_inicial][x],gols_cres[ano-ano_inicial][x],x,artilheiro_liga[ano-ano_inicial][x],gols_cres_liga[ano-ano_inicial][x]);}     
	          if(gols_cres[ano-ano_inicial][x]>0)printf("                                             9- %s %d ",artilheiro[ano-ano_inicial][9],gols_cres[ano-ano_inicial][9]);if(gols_cres_liga[ano-ano_inicial][9]>0)printf("    9 - %s %d\n",artilheiro_liga[ano-ano_inicial][9],gols_cres_liga[ano-ano_inicial][9]);else{printf("\n");}
			  			  for(x=10;x<=15;x++){ if(x==10)printf("%s - %s",ntime[minha_liga][chave1],ntime[minha_liga][chave2]);
			  					   if(x==11)printf("%s - %s",ntime[minha_liga][chave3],ntime[minha_liga][chave4]);
								   if(x==12)printf("%s - %s",ntime[minha_liga][chave5],ntime[minha_liga][chave6]);	
								   if(x==13)printf("%s - %s",ntime[minha_liga][chave7],ntime[minha_liga][chave8]);		
	  			  				   if(x==14||x==15)printf("                                 ");	
			  
			  				if(gols_cres[ano-ano_inicial][x]>0)printf("            %d- %s%d ",x,artilheiro[ano-ano_inicial][x],gols_cres[ano-ano_inicial][x]);
				  			if(gols_cres_liga[ano-ano_inicial][x]>0)printf("    %d- %s %d\n",x,artilheiro_liga[ano-ano_inicial][x],gols_cres_liga[ano-ano_inicial][x]);
							  else printf("\n");}
	          				  
	   
   if (campeonato>=1){printf("Ano:%d   Rodada:%d\n\n",ano,fase);
		               printf("CHAMPIONS LEAGUE");
						 printf("\nGrupo 1:\n");
                       for(x=1;x<=4;x++){printf("%d-",x);tabela(ntime_cres[0][x]);printf("%s",ntime_cres[0][x]);textcolor(7,0);printf(" %d %.2f\n",p_cres[0][x],rnk_cres[0][x]);}
					   printf("\nGrupo 2:\n");
                       for(x=5;x<=8;x++){printf("%d-",x-4);tabela(ntime_cres[0][x]);printf("%s",ntime_cres[0][x]);textcolor(7,0);printf(" %d %.2f\n",p_cres[0][x],rnk_cres[0][x]);}
					   	printf("\nGrupo 3:\n");
                       for(x=9;x<=12;x++){printf("%d-",x-8);tabela(ntime_cres[0][x]);printf("%s",ntime_cres[0][x]);textcolor(7,0);printf(" %d %.2f\n",p_cres[0][x],rnk_cres[0][x]);}
					   printf("\nGrupo 4:\n");
                       for(x=13;x<=16;x++){printf("%d-",x-12);tabela(ntime_cres[0][x]);printf("%s",ntime_cres[0][x]);textcolor(7,0);printf(" %d %.2f\n",p_cres[0][x],rnk_cres[0][x]);}
					if (campeonato==1){
					for(x=0;x<=15;x=x+4){printf("\n");  
					   printf("%s - %s\n",champions[chave1+x],champions[chave2+x]);
					   printf("%s - %s\n",champions[chave3+x],champions[chave4+x]);}}		 
                             }
                             
          if (campeonato==2){printf("Ano:%d   Rodada:%d\n\n",ano,fase);
                             printf("CHAMPIONS LEAGUE\n\n");
                             if(fase==7)n=8;if(fase==8)n=4;if(fase==9)n=2;
		                for(x=1;x<=n;x=x+2){printf("%s - %s\n",champions[x],champions[x+1]);}  
		                }
		                
						printf("\n(Q)Outras ligas\n");
						printf("-Qualquer Outra Tecla para sair-\n");	                
			int	escolha =  getch();
			if(escolha=='q'){	  //OUTRAS LIGAS
			   system("cls");
			   printf("\n");
	          for(x=1;x<=n_times;x++){for(i=1;i<=4;i++){
	          						if(x==1){tabela(ntime_cres[i][x]);} printf("%s %d ",ntime_cres[i][x],p_cres[i][x]);textcolor(7,0);//pinta 1ºvalor
			  		if(p_cres[i][x]<10)printf(" ");printf("  %d",gols_feitos_cres[i][x]);if(gols_feitos_cres[i][x]<10)printf(" ");printf(" %d    ",gols_tomados_cres[i][x]);if(gols_tomados_cres[i][x]<10)printf(" ");   } printf("\n");}
              printf("\n");
	          for(x=1;x<=n_times;x++){for(i=5;i<=7;i++){
	          						if(x==1){tabela(ntime_cres[i][x]);} printf("%s %d ",ntime_cres[i][x],p_cres[i][x]);textcolor(7,0);//pinta 1ºvalor
			  		if(p_cres[i][x]<10)printf(" ");printf("  %d",gols_feitos_cres[i][x]);if(gols_feitos_cres[i][x]<10)printf(" ");printf(" %d    ",gols_tomados_cres[i][x]);if(gols_tomados_cres[i][x]<10)printf(" ");   } printf("\n");}
              printf("\n");
	          for(x=1;x<=n_times;x++){for(i=8;i<=11;i++){
	          						if(x==1){tabela(ntime_cres[i][x]);} printf("%s %d ",ntime_cres[i][x],p_cres[i][x]);textcolor(7,0);//pinta 1ºvalor
			  		if(p_cres[i][x]<10)printf(" ");printf("  %d",gols_feitos_cres[i][x]);if(gols_feitos_cres[i][x]<10)printf(" ");printf(" %d    ",gols_tomados_cres[i][x]);if(gols_tomados_cres[i][x]<10)printf(" ");   } printf("\n");}
              printf("\n");
			  for(x=1;x<=n_times;x++){for(i=11;i<n_ligas;i++){if(i!=minha_liga){  //mostra a classificaçao das outras ligas
			  					  if(x==1){tabela(ntime_cres[i][x]);} printf("%s %d ",ntime_cres[i][x],p_cres[i][x]);textcolor(7,0);//pinta 1ºvalor
			  		if(p_cres[i][x]<10)printf(" ");printf("  %d",gols_feitos_cres[i][x]);if(gols_feitos_cres[i][x]<10)printf(" ");printf(" %d    ",gols_tomados_cres[i][x]);if(gols_tomados_cres[i][x]<10)printf(" ");   }} printf("\n");}
			  printf("\n");
			  getch();
		}//Escolheu q
				  	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////q
    if(op==3){char transferencia[NLISTA][60];//nº de jogadores na lista
              float lista_valor[NLISTA];
              char lista_time[NLISTA][20];
			  int lista_idade[NLISTA],lista_overall[NLISTA];
              int escolha;
              preco_jogador();
              printf("Transferencias:\n  Posicao:\n");
              printf("                           |PTS|IDADE|PRECO \n");
              for(x=1;x<=9;x++){printf("%d-%s:%s |%d | %d  | %.3f \n",x,position[minha_liga][timea][x],jog[minha_liga][timea][x],overall[minha_liga][timea][x],idade[minha_liga][timea][x],preco[minha_liga][timea][x]);}
              for(x=10;x<n_posicoes;x++){if(x==12)printf("\n");printf("%d-%s:%s|%d | %d  | %.3f \n",x,position[minha_liga][timea][x],jog[minha_liga][timea][x],overall[minha_liga][timea][x],idade[minha_liga][timea][x],preco[minha_liga][timea][x]);}
              printf("   (0)Voltar\n");

            scanf("%d",&escolha);
            system("cls");          
						
if(escolha>0 && escolha<=n_posicoes){  
            
//ORGANIZA            
            printf("ORGANIZAR POR:\n");
              printf(" (1)Por Overall\n");
              printf(" (2)Por Idade\n");
              printf(" (3)Por Preco\n");
              printf(" (4)Por Time\n");
              printf(" (5)So na sua liga\n");
              printf("\n (6)Outras Posicoes\n");
              int organiza;
            organiza=getch()-48;
            
            //Procura os jogadores da mesma posição  
	     n=1;            
       for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){
       		if (organiza==5){var_n_ligas=minha_liga;  }
		    for(x=1;x<=n_times;x++){
            for(y=1;y<=n_posicoes;y++){
            	if(x!=timea || var_n_ligas!=minha_liga ){
			       if(strcmp(position[var_n_ligas][x][y],position[minha_liga][timea][escolha])==0 ){
			       	//Restriçoes pra nao estourar um execesso de jogadores MEI e travar o programa
			       	if ((strcmp(position[var_n_ligas][x][y],"MEI")!=0)||((organiza==5 && var_n_ligas==minha_liga)||(organiza==1 && overall[var_n_ligas][x][y]>=76) ||(organiza==2 && idade[var_n_ligas][x][y]<28) ||(organiza==3 && preco[var_n_ligas][x][y]>10)||(organiza==4 && preco[var_n_ligas][x][y]>10))){
					strcpy(transferencia[n],jog[var_n_ligas][x][y]);strcpy(lista_time[n],ntime[var_n_ligas][x]);lista_valor[n]=preco[var_n_ligas][x][y];lista_idade[n]=idade[var_n_ligas][x][y];lista_overall[n]=overall[var_n_ligas][x][y];
					n++;}}}//if
					 }			 }
              if (organiza==5){break;}                     							}//for  
    
                                   							
            
if(organiza==1 || organiza==5){
					for(i=1;i<=n;i++){
                	for( x=i+1; x<=n; x++ ){
                      if(lista_overall[i]<lista_overall[x]){
					  auxiliar_int=lista_overall[i];lista_overall[i]=lista_overall[x];lista_overall[x]=auxiliar_int;
					  auxiliar_float=lista_valor[i];lista_valor[i]=lista_valor[x];lista_valor[x]=auxiliar_float;
					  auxiliar_int=lista_idade[i];lista_idade[i]=lista_idade[x];lista_idade[x]=auxiliar_int;
                      strcpy(auxiliar,transferencia[i]);strcpy(transferencia[i],transferencia[x]);strcpy(transferencia[x],auxiliar);
                      strcpy(auxiliar,lista_time[i]);strcpy(lista_time[i],lista_time[x]);strcpy(lista_time[x],auxiliar);
                                 }}}}
if(organiza==2){					for(i=1;i<=n;i++){
                	for( x=i+1; x<n; x++ ){
                      if(lista_idade[i]>lista_idade[x]){
                      	auxiliar_int=lista_overall[i];lista_overall[i]=lista_overall[x];lista_overall[x]=auxiliar_int;
                      	auxiliar_float=lista_valor[i];lista_valor[i]=lista_valor[x];lista_valor[x]=auxiliar_float;
					  auxiliar_int=lista_idade[i];lista_idade[i]=lista_idade[x];lista_idade[x]=auxiliar_int;
                      strcpy(auxiliar,transferencia[i]);strcpy(transferencia[i],transferencia[x]);strcpy(transferencia[x],auxiliar);
                      strcpy(auxiliar,lista_time[i]);strcpy(lista_time[i],lista_time[x]);strcpy(lista_time[x],auxiliar);
                                 }}}}
if(organiza==3){					for(i=1;i<=n;i++){
                	for( x=i+1; x<=n; x++ ){
                      if(lista_valor[i]<lista_valor[x]){
                      	auxiliar_int=lista_overall[i];lista_overall[i]=lista_overall[x];lista_overall[x]=auxiliar_int;
					  auxiliar_float=lista_valor[i];lista_valor[i]=lista_valor[x];lista_valor[x]=auxiliar_float;
					  auxiliar_int=lista_idade[i];lista_idade[i]=lista_idade[x];lista_idade[x]=auxiliar_int;
                      strcpy(auxiliar,transferencia[i]);strcpy(transferencia[i],transferencia[x]);strcpy(transferencia[x],auxiliar);
                      strcpy(auxiliar,lista_time[i]);strcpy(lista_time[i],lista_time[x]);strcpy(lista_time[x],auxiliar);
                                 }}}} 
system("cls");                     
if(organiza==6){printf(" (1)GOL\n");printf(" (2)ZAG\n");printf(" (3)LAT\n");printf(" (4)VOL\n");printf(" (5)MEI\n");printf(" (6)ATA\n");
			  organiza=getch()-48;    
			  if(organiza==1){strcpy(auxiliar,"GOL");}if(organiza==2){strcpy(auxiliar,"ZAG");}if(organiza==3){strcpy(auxiliar,"LAT");}if(organiza==4){strcpy(auxiliar,"VOL");}if(organiza==5){strcpy(auxiliar,"MEI");}if(organiza==6){strcpy(auxiliar,"ATA");}
			              //Procura os jogadores da mesma posição  
	     n=1;            
       for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){
		    for(x=1;x<=n_times;x++){
            for(y=1;y<=n_posicoes;y++){
            	if(x!=timea || var_n_ligas!=minha_liga ){
			       if(strcmp(position[var_n_ligas][x][y],auxiliar)==0 ){
			       	//Restriçoes pra nao estourar um execesso de jogadores MEI e travar o programa
			       	strcpy(transferencia[n],jog[var_n_ligas][x][y]);strcpy(lista_time[n],ntime[var_n_ligas][x]);lista_valor[n]=preco[var_n_ligas][x][y];lista_idade[n]=idade[var_n_ligas][x][y];lista_overall[n]=overall[var_n_ligas][x][y];
					n++;}}//if
					 }			 }                    							}//for 
		//Organiza por Overall
		for(i=1;i<=n;i++){
                	for( x=i+1; x<=n; x++ ){
                      if(lista_overall[i]<lista_overall[x]){
					  auxiliar_int=lista_overall[i];lista_overall[i]=lista_overall[x];lista_overall[x]=auxiliar_int;
					  auxiliar_float=lista_valor[i];lista_valor[i]=lista_valor[x];lista_valor[x]=auxiliar_float;
					  auxiliar_int=lista_idade[i];lista_idade[i]=lista_idade[x];lista_idade[x]=auxiliar_int;
                      strcpy(auxiliar,transferencia[i]);strcpy(transferencia[i],transferencia[x]);strcpy(transferencia[x],auxiliar);
                      strcpy(auxiliar,lista_time[i]);strcpy(lista_time[i],lista_time[x]);strcpy(lista_time[x],auxiliar);
                                 }}}	  
			  }                            	          
if(n>100)for(i=n-1;i>=100;i--){                           
            printf("\n%d-(%s)%s |%d | %d  |%.1f",i,lista_time[i],transferencia[i],lista_overall[i],lista_idade[i],lista_valor[i]);
			if(preco[minha_liga][timea][escolha]+grana>=lista_valor[i]){printf(" + ");			}
			}
if(n>99)k=99;else k=n-1;
for(i=k;i>=10;i--){                           
            printf("\n%d- (%s)%s |%d | %d  |%.1f",i,lista_time[i],transferencia[i],lista_overall[i],lista_idade[i],lista_valor[i]);
			if(preco[minha_liga][timea][escolha]+grana>=lista_valor[i]){printf(" + ");			}
			}	
for(i=9;i>=1;i--){                           
            printf("\n%d - (%s)%s |%d | %d  |%.1f",i,lista_time[i],transferencia[i],lista_overall[i],lista_idade[i],lista_valor[i]);
			if(preco[minha_liga][timea][escolha]+grana>=lista_valor[i]){printf(" + ");			}
			}					
printf("\n\n%s:%s |%d | %d  |%.1f\nDINHEIRO: %.3f\n",position[minha_liga][timea][escolha],jog[minha_liga][timea][escolha],overall[minha_liga][timea][escolha],idade[minha_liga][timea][escolha],preco[minha_liga][timea][escolha],grana);
  				    
								   							
        int escolha2;  
		scanf("%d",&escolha2);
	if(escolha2>0 && preco[minha_liga][timea][escolha]+grana>=lista_valor[i] && escolha2<n){	
		 for(var_n_ligas=1;var_n_ligas<n_ligas;var_n_ligas++){
		    for(x=1;x<=n_times;x++){
            for(y=1;y<=n_posicoes;y++){		
		if(strcmp(jog[var_n_ligas][x][y],transferencia[escolha2])==0)//se achar o jogador igual
		{
		if(grana+preco[minha_liga][timea][escolha]-preco[var_n_ligas][x][y]<0){
			system("cls");printf("SEM DINHEIRO!!!");Beep(400,800);}
		else{
		system("cls");printf("TRANSFERENCIA CONCLUIDA POR: \n\n%s - %s \n\nHABILIDADE: %d\nIDADE: %d \nJOGOS CARREIRA: %d\nGOLS TEMPORADA: %d",position[var_n_ligas][x][y],transferencia[escolha2],overall[var_n_ligas][x][y],idade[var_n_ligas][x][y],jogados[var_n_ligas][x][y],gols[var_n_ligas][x][y] );
		if(preco[var_n_ligas][x][y]>100){status[4]=1;}//meta de comprar jogador de 100 milhoes	
		strcpy(auxiliar,jog[var_n_ligas][x][y]);strcpy(jog[var_n_ligas][x][y],jog[minha_liga][timea][escolha]);strcpy(jog[minha_liga][timea][escolha],auxiliar);
		auxiliar_int=idade[minha_liga][timea][escolha];     idade[minha_liga][timea][escolha]=idade[var_n_ligas][x][y];          idade[var_n_ligas][x][y]=auxiliar_int;
		auxiliar_int=overall[minha_liga][timea][escolha];   overall[minha_liga][timea][escolha]=overall[var_n_ligas][x][y];      overall[var_n_ligas][x][y]=auxiliar_int;
		auxiliar_int=overallMax[minha_liga][timea][escolha];overallMax[minha_liga][timea][escolha]=overallMax[var_n_ligas][x][y];overallMax[var_n_ligas][x][y]=auxiliar_int;
		auxiliar_int=gols[minha_liga][timea][escolha];       gols[minha_liga][timea][escolha]=gols[var_n_ligas][x][y];           gols[var_n_ligas][x][y]=auxiliar_int;
		grana=grana+preco[minha_liga][timea][escolha]-preco[var_n_ligas][x][y];
		auxiliar_int=jogados[minha_liga][timea][escolha];     jogados[minha_liga][timea][escolha]=jogados[var_n_ligas][x][y];      jogados[var_n_ligas][x][y]=auxiliar_int;
		auxiliar_int=amarelo[minha_liga][timea][escolha];     amarelo[minha_liga][timea][escolha]=amarelo[var_n_ligas][x][y];      amarelo[var_n_ligas][x][y]=auxiliar_int;
		auxiliar_int=vermelho[minha_liga][timea][escolha];    vermelho[minha_liga][timea][escolha]=vermelho[var_n_ligas][x][y];      vermelho[var_n_ligas][x][y]=auxiliar_int;
		auxiliar_int=machucado[minha_liga][timea][escolha];   machucado[minha_liga][timea][escolha]=machucado[var_n_ligas][x][y];      machucado[var_n_ligas][x][y]=auxiliar_int;
		strcpy(auxiliar,position[var_n_ligas][x][y]);strcpy(position[var_n_ligas][x][y],position[minha_liga][timea][escolha]);strcpy(position[minha_liga][timea][escolha],auxiliar);
		getch();
	}
		break;}
		}}}//busca jogador
      }
}//if escolheu jogador

			}
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////q
    if(op==4){int qaz=1,qwerty,qwe;
              while(qaz!=0){
			  system("cls");preco_jogador();
                               printf("Minha Equipe:           \n\nDinheiro:");printf("R$%.3f\n",grana);
              printf("                           |PTS|IDADE| JOG |GOLS |AMA|VER|LES|PRECO\n");
              for(x=1;x<=9;x++)  {printf("%d-%s:%s |%d | %d  |  %d ",x,position[minha_liga][timea][x],jog[minha_liga][timea][x],overall[minha_liga][timea][x],idade[minha_liga][timea][x],jogados[minha_liga][timea][x]);if(jogados[minha_liga][timea][x]<10)printf(" ");printf("|  %d  |",gols[minha_liga][timea][x]);textcolor(6,0);printf(" %d ",amarelo[minha_liga][timea][x]);textcolor(7,0);printf("|");textcolor(4,0);printf(" %d ",vermelho[minha_liga][timea][x]);textcolor(7,0);printf("| %d |%.2f\n",machucado[minha_liga][timea][x],preco[minha_liga][timea][x]);}
              for(x=10;x<n_posicoes;x++){if(x==12)printf("\n"); 
			  					printf("%d-%s:%s|%d | %d  |  %d ",x,position[minha_liga][timea][x],jog[minha_liga][timea][x],overall[minha_liga][timea][x],idade[minha_liga][timea][x],jogados[minha_liga][timea][x]);if(jogados[minha_liga][timea][x]<10)printf(" ");printf("|  %d  |",gols[minha_liga][timea][x]);textcolor(6,0);printf(" %d ",amarelo[minha_liga][timea][x]);textcolor(7,0);printf("|");textcolor(4,0);printf(" %d ",vermelho[minha_liga][timea][x]);textcolor(7,0);printf("| %d |%.2f\n",machucado[minha_liga][timea][x],preco[minha_liga][timea][x]);}	
			  printf("\n(0)Voltar");  
              printf("\n(1)Mudar jogadores de posicao");
              printf("\n(2)Organizar sozinho\n\n");
			  qaz=getch()-48;

         if(qaz==1){
              printf("Quem por quem? ");
              scanf("%d",&qwerty);
        if(qwerty>0 && qwerty<n_posicoes){ 
              printf("%s",jog[minha_liga][timea][qwerty]);
              printf("\n\nPor? ");
              scanf("%d",&qwe);
              printf("%s",jog[minha_liga][timea][qwe]);
        if(strcmp(position[minha_liga][timea][qwerty],position[minha_liga][timea][qwe])==0){
        if(qwe>0 && qwe<n_posicoes){      
            strcpy(auxiliar,jog[minha_liga][timea][qwerty]);    strcpy(jog[minha_liga][timea][qwerty],jog[minha_liga][timea][qwe]);      strcpy(jog[minha_liga][timea][qwe],auxiliar);
	   		strcpy(auxiliar,position[minha_liga][timea][qwerty]);strcpy(position[minha_liga][timea][qwerty],position[minha_liga][timea][qwe]);strcpy(position[minha_liga][timea][qwe],auxiliar);
			auxiliar_int=idade[minha_liga][timea][qwerty];     idade[minha_liga][timea][qwerty]=idade[minha_liga][timea][qwe];          idade[minha_liga][timea][qwe]=auxiliar_int;
			auxiliar_int=overall[minha_liga][timea][qwerty];   overall[minha_liga][timea][qwerty]=overall[minha_liga][timea][qwe];      overall[minha_liga][timea][qwe]=auxiliar_int;
			auxiliar_int=overallMax[minha_liga][timea][qwerty];overallMax[minha_liga][timea][qwerty]=overallMax[minha_liga][timea][qwe];overallMax[minha_liga][timea][qwe]=auxiliar_int;
		    auxiliar_int=preco[minha_liga][timea][qwerty];     preco[minha_liga][timea][qwerty]=preco[minha_liga][timea][qwe];          preco[minha_liga][timea][qwe]=auxiliar_int;
			auxiliar_int=gols[minha_liga][timea][qwerty];      gols[minha_liga][timea][qwerty]=gols[minha_liga][timea][qwe];            gols[minha_liga][timea][qwe]=auxiliar_int;
			auxiliar_int=amarelo[minha_liga][timea][qwerty];                      amarelo[minha_liga][timea][qwerty]=amarelo[minha_liga][timea][qwe];     			  amarelo[minha_liga][timea][qwe]=auxiliar_int;
			auxiliar_int=vermelho[minha_liga][timea][qwerty];                      vermelho[minha_liga][timea][qwerty]=vermelho[minha_liga][timea][qwe];     		  vermelho[minha_liga][timea][qwe]=auxiliar_int;
			auxiliar_int=machucado[minha_liga][timea][qwerty];                      machucado[minha_liga][timea][qwerty]=machucado[minha_liga][timea][qwe];				machucado[minha_liga][timea][qwe]=auxiliar_int;
			auxiliar_int=jogados[minha_liga][timea][qwerty];                      jogados[minha_liga][timea][qwerty]=jogados[minha_liga][timea][qwe];				jogados[minha_liga][timea][qwe]=auxiliar_int;

									}else{printf("\nPOSICAO INEXISTENTE");Beep(400,500);}}
		 else {system("cls");printf("\nPOSICAO DIFERENTE!!!");Beep(400,500);}
									}//if qwerty>0
									}//if qwerty==1
	//poe os jogadores mais fortes por posicao no clube	
	if(qaz==2){
            for(y=1;y<=11;y++){				  //y=posição de referencia
			for(z=y+1;z<=n_posicoes;z++){k=0; // z=posição procurada
				if((y==1)        && strcmp("GOL",position[minha_liga][timea][z])==0)k=1;
				if((y==2)        && strcmp("LAT",position[minha_liga][timea][z])==0)k=1;
				if((y==3 || y==4)&& strcmp("ZAG",position[minha_liga][timea][z])==0)k=1;
				if((y==5)        && strcmp("LAT",position[minha_liga][timea][z])==0)k=1;
				if((y==6 || y==7)&& strcmp("VOL",position[minha_liga][timea][z])==0)k=1;	
				if((y==8 || y==9)&& strcmp("MEI",position[minha_liga][timea][z])==0)k=1;
				if((y==10||y==11)&& strcmp("ATA",position[minha_liga][timea][z])==0)k=1;		
								
						if(k==1 && ((overall[minha_liga][timea][y]<overall[minha_liga][timea][z] && machucado[minha_liga][timea][z]==0 && vermelho[minha_liga][timea][z]==0 && amarelo[minha_liga][timea][z]<=2 ) || (machucado[minha_liga][timea][y]>0 || vermelho[minha_liga][timea][y]==1 || amarelo[minha_liga][timea][y]>=3))
						        || (k==1 &&   (amarelo[minha_liga][timea][y]==3 || vermelho[minha_liga][timea][y]==1 || machucado[minha_liga][timea][y]>0))
				   		){
										strcpy(auxiliar,jog[minha_liga][timea][z]);strcpy(jog[minha_liga][timea][z],jog[minha_liga][timea][y]);strcpy(jog[minha_liga][timea][y],auxiliar);
										auxiliar_int=idade[minha_liga][timea][z];     idade[minha_liga][timea][z]=idade[minha_liga][timea][y];          idade[minha_liga][timea][y]=auxiliar_int;
										auxiliar_int=overall[minha_liga][timea][z];   overall[minha_liga][timea][z]=overall[minha_liga][timea][y];      overall[minha_liga][timea][y]=auxiliar_int;
										auxiliar_int=overallMax[minha_liga][timea][z];overallMax[minha_liga][timea][z]=overallMax[minha_liga][timea][y];overallMax[minha_liga][timea][y]=auxiliar_int;
						  		    	auxiliar_int=preco[minha_liga][timea][z];     preco[minha_liga][timea][z]=preco[minha_liga][timea][y];          preco[minha_liga][timea][y]=auxiliar_int;
			   						    auxiliar_int=gols[minha_liga][timea][z];      gols[minha_liga][timea][z]=gols[minha_liga][timea][y];            gols[minha_liga][timea][y]=auxiliar_int;		
									   	strcpy(auxiliar,position[minha_liga][timea][z]);strcpy(position[minha_liga][timea][z],position[minha_liga][timea][y]);strcpy(position[minha_liga][timea][y],auxiliar);
									auxiliar_int=amarelo[minha_liga][timea][z];                      amarelo[minha_liga][timea][z]=amarelo[minha_liga][timea][y];     			  amarelo[minha_liga][timea][y]=auxiliar_int;
									auxiliar_int=vermelho[minha_liga][timea][z];                      vermelho[minha_liga][timea][z]=vermelho[minha_liga][timea][y];     		  vermelho[minha_liga][timea][y]=auxiliar_int;
									auxiliar_int=machucado[minha_liga][timea][z];                      machucado[minha_liga][timea][z]=machucado[minha_liga][timea][y];				machucado[minha_liga][timea][y]=auxiliar_int;
									auxiliar_int=jogados[minha_liga][timea][z];                      jogados[minha_liga][timea][z]=jogados[minha_liga][timea][y];     		  jogados[minha_liga][timea][y]=auxiliar_int;
								}							 
												}}  	}							
									
	}//while
    }	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////q	            
if(op==5){
			  printf("Jogador do Ano:\n\n");  	
		  for(x=2;x<=ano-ano_inicial;x++){printf("%d- %s %s %s %s %s\n",x+ano_inicial-1,melhor_mundo[x][1],melhor_mundo[x][2],melhor_mundo[x][3],melhor_mundo[x][4],melhor_mundo[x][5]); }  
		  	
		  printf("\nArtilheiro do Ano:\n\n");  	
		  for(x=1;x<=ano-ano_inicial-1;x++){printf("%d- %s %d gols    %s %d gols     %s %d gols \n",x+ano_inicial,artilheiro[x][1],gols_cres[x][1],artilheiro[x][2],gols_cres[x][2],artilheiro[x][3],gols_cres[x][3]); }  	
		   	           
printf("\n Europeus:\n\n");
				for(x=1;x<ano-ano_inicial;x++){
		  										printf("%d- ",x+ano_inicial);
												for(y=1;y<8;y++){tabela(nacional[x][y]);printf("%s ",nacional[x][y]);}//y=8 campeoes dos paises
												textcolor(7,0);printf("\n");}
												//se olhar depois que os times forem campeoes
		  if(campeonato>=1){                	printf("%d- ",x+2017);
												for(y=1;y<8;y++){tabela(nacional[x][y]);printf("%s ",nacional[x][y]);}//y=8 campeoes dos paises
												textcolor(7,0);printf("\n");} 
		  printf("\nOutros Campeoes:\n\n");
				for(x=1;x<ano-ano_inicial;x++){
		  										printf("%d- ",x+ano_inicial);
								for(y=8;y<n_ligas;y++){tabela(nacional[x][y]);printf("%s ",nacional[x][y]);}//y=8 campeoes dos paises
												textcolor(7,0);printf("\n");}
												//se olhar depois que os times forem campeoes
		  if(campeonato>=1){                	printf("%d- ",x+2017);
								for(y=8;y<n_ligas;y++){tabela(nacional[x][y]);printf("%s ",nacional[x][y]);}//y=8 campeoes dos paises
												textcolor(7,0);printf("\n");} 										
		  
		  printf("\nChampions League:\n\n");printf("      Campeao         Vice               Semifinal:\n");	
		    	for(x=1;x<=ano-ano_inicial;x++){printf("%d- ",x+ano_inicial);tabela(campeao[x]);printf("%s ",campeao[x]);		tabela(vice[x]);printf("%s ",vice[x]);	textcolor(7,0);printf("||");
																		      tabela(terceiro[x]);printf(" %s ",terceiro[x]);   tabela(quarto[x]);printf("%s\n",quarto[x]);		textcolor(7,0);}
getch();}    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////q	
if(op==6){
printf("Escolha a Liga:\n");
	for(x=1;x<n_ligas;x++){printf("(%d)%s\n",x,ntime[x][0]);}	
scanf("%d",&j);
system("cls");   
if(j>=1 && j<n_ligas){
minha_liga=j;
printf("Escolha o seu time:\n");
         for(n=1;n<=n_times;n++){printf("(%d)%s\n",n,ntime[minha_liga][n]); }	
		 timea=getch()-48;
		 grana=(rnk[minha_liga][timea]-70)*(rnk[minha_liga][timea]-70)/2;
		 if(status[3]<50)status[3]=0;
		 //for(x=2;x<=n_posicoes;x++){vermelho[x]=0;amarelo[minha_liga][x]=0;	machucado[x]=0;}
		 }
else j=minha_liga;		 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////q
if(op==7){
printf("METAS:\n");
printf("\nSeja campeao da liga nacional   : ");if(status[1]==1)printf("COMPLETO");
printf("\nSeja campeao da Champions League: ");if(status[2]==1)printf("COMPLETO");
printf("\nVenca 50 jogos no mesmo time    : ");if(status[3]>=50)printf("COMPLETO");
printf("\nContrate um jogador >100milhoes : ");if(status[4]==1)printf("COMPLETO");
printf("\nTemporada nacional Invicto      : ");if(status[5]==1)printf("COMPLETO");
printf("\nTenha o artilheiro do ano       : ");
									for( x=1; x<ano-ano_inicial; x++ ){
										for( i=1; i<=n_posicoes; i++ ){
									if(strcmp(jog[minha_liga][timea][i],artilheiro[x][1])==0)printf("COMPLETO");}}
printf("\nJogue 5 temporadas              : ");if(ano>=2022)printf("COMPLETO");

printf("\n\n Historico:\n");
for(x=1;x<=ano-ano_inicial;x++){printf("%d- %d lugar\n",x+ano_inicial, minha_posicao[x]);}
getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////q	
if((op=='a'-'0')&&(grana>=soma_precos)){grana=grana-soma_precos;contrato=contrato+10;printf("\nContratos Renovados em +10 partidas");_sleep(800);} 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////q	
if(op=='f'-'0') {if(FALTAS==1)FALTAS=0;
				 else {FALTAS=1;printf("\nFaltas e Cartoes Ativos");_sleep(800);}} 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////q
}//WHILE NO MENU PRINCIPAL
	return 0;
}
