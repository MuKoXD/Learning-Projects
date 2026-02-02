#include <iostream>
#include <string> 


struct SpecialDatesInfo{
  bool SpecialDatesPre[13][32]={false};
  std::string SpecialTitles[13][3];
};

struct AddSpecialDates{
  bool CustomSpecialDates[13][32]= {false};
  std::string CustomSpecialTitles[13][32];
};

bool LeapYearCheck(int year){
  if(year%4==0 && (year%100!=0||year%400==0)){
    return true;
  }else{
    return false;
  }
}

int FirstDayOfTheMonth(int day, int month, int year){
  long long weekDay;
  int LeapYears= ((year-1)/4)-((year-1)/100)+((year-1)/400);
  

  weekDay= (((year-1)-LeapYears)*365)+(LeapYears*366);
  switch (month){
    case 1:
      weekDay+=0;
    break;
    case 2:
      weekDay+=31;
    break;
    case 3:
      weekDay+=59;
    break;
    case 4:
      weekDay+=90;
    break;
    case 5:
      weekDay+=120;
    break;
    case 6:
      weekDay+=151;
    break;
    case 7:
      weekDay+=181;
    break;
    case 8:
      weekDay+=212;
    break;
    case 9:
      weekDay+=243;
    break;
    case 10:
      weekDay+=273;
    break;
    case 11:
      weekDay+=304;
    break;
    case 12:
      weekDay+=334;
    break;
  }
  LeapYearCheck(year) && month>2? weekDay+=day+1:weekDay+=day;
  return weekDay%7;
}

void DrawMonth(int month, int year,int MonthLengh[], SpecialDatesInfo AllSpecialDates, AddSpecialDates AddedDates){
  int Firstday= FirstDayOfTheMonth(01,month, year)-1;
  int LineNumbers=1;
  int TodaysDay=1;
  int startDayLoop;

  
  switch(month){
    case 1:
      std::cout << "=================================================" << std::endl;
      std::cout << "                     JANEIRO                     " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
    case 2:
      std::cout << "=================================================" << std::endl;
      std::cout << "                    FEVEREIRO                    " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
    case 3:
      std::cout << "=================================================" << std::endl;
      std::cout << "                      MARÇO                      " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
    case 4:
      std::cout << "=================================================" << std::endl;
      std::cout << "                      ABRIL                      " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
    case 5:
      std::cout << "=================================================" << std::endl;
      std::cout << "                       MAIO                      " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
    case 6:
      std::cout << "=================================================" << std::endl;
      std::cout << "                      JUNHO                      " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
    case 7:
      std::cout << "=================================================" << std::endl;
      std::cout << "                      JULHO                      " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
    case 8:
      std::cout << "=================================================" << std::endl;
      std::cout << "                     AGOSTO                      " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
    case 9:
      std::cout << "=================================================" << std::endl;
      std::cout << "                    SETEMBRO                     " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
    case 10:
      std::cout << "=================================================" << std::endl;
      std::cout << "                     OUTUBRO                     " << std::endl;
    std::cout << "=================================================" << std::endl;
    break;
    case 11:
      std::cout << "=================================================" << std::endl;
      std::cout << "                    NOVEMBRO                     " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
    case 12:
      std::cout << "=================================================" << std::endl;
      std::cout << "                    DEZEMBRO                     " << std::endl;
      std::cout << "=================================================" << std::endl;
    break;
  }

  std::cout << "| Dom || Seg || Ter || Qua || Qui || Sex || Sáb |" << std::endl;

  for(int i=0;i<6;i++){
    startDayLoop=TodaysDay;
    for(int j=-1;j<6;j++){
      /*feriado padrão ()
      feriado adicionado []
      feriado ambos {}*/
      int SpecialDay=0;
      if(AllSpecialDates.SpecialDatesPre[month][TodaysDay]==true && AddedDates.CustomSpecialDates[month][TodaysDay]==true){
        SpecialDay=3;
      }else if(AllSpecialDates.SpecialDatesPre[month][TodaysDay]==true){
        SpecialDay=1;
      }else if(AddedDates.CustomSpecialDates[month][TodaysDay]==true){
        SpecialDay=2;
      }

      if(LineNumbers<=21){
          if(LineNumbers<=7){
            if(j<Firstday){
              std::cout << "|  ·  |";
            }else{
                if(SpecialDay!=0){
                   if(SpecialDay==1){
                    std::cout << "| (" << TodaysDay <<") |";
                    TodaysDay++;
                   }else if(SpecialDay==2){
                    std::cout << "| [" << TodaysDay <<"] |";
                    TodaysDay++;
                   }else{
                    std::cout << "| {" << TodaysDay <<"} |";
                    TodaysDay++;
                   }
                }else{
                  std::cout << "|  " << TodaysDay <<"  |";
                  TodaysDay++;
                }
            }
          }else if(LineNumbers<=14){
              if(TodaysDay>9){
                if(SpecialDay!=0){
                  if(SpecialDay==1){
                    std::cout << "|(" << TodaysDay <<") |";
                    TodaysDay++;
                   }else if(SpecialDay==2){
                    std::cout << "|[" << TodaysDay <<"] |";
                    TodaysDay++;
                   }else{
                    std::cout << "|{" << TodaysDay <<"} |";
                    TodaysDay++;
                   }
                }else{
                  std::cout << "| " << TodaysDay <<"  |";
                  TodaysDay++;
                }
              }else{
                if(SpecialDay!=0){
                   if(SpecialDay==1){
                    std::cout << "| (" << TodaysDay <<") |";
                    TodaysDay++;
                   }else if(SpecialDay==2){
                    std::cout << "| [" << TodaysDay <<"] |";
                    TodaysDay++;
                   }else{
                    std::cout << "| {" << TodaysDay <<"} |";
                    TodaysDay++;
                   }
                }else{
                  std::cout << "|  " << TodaysDay <<"  |";
                  TodaysDay++;
                }
              }
          }else{
            if(SpecialDay!=0){
                  if(SpecialDay==1){
                    std::cout << "|(" << TodaysDay <<") |";
                    TodaysDay++;
                   }else if(SpecialDay==2){
                    std::cout << "|[" << TodaysDay <<"] |";
                    TodaysDay++;
                   }else{
                    std::cout << "|{" << TodaysDay <<"} |";
                    TodaysDay++;
                   }
                }else{
                  std::cout << "| " << TodaysDay <<"  |";
                  TodaysDay++;
                }
          }
        }else{
          if(LineNumbers<=28){
            if(SpecialDay!=0){
                  if(SpecialDay==1){
                    std::cout << "|(" << TodaysDay <<") |";
                    TodaysDay++;
                   }else if(SpecialDay==2){
                    std::cout << "|[" << TodaysDay <<"] |";
                    TodaysDay++;
                   }else{
                    std::cout << "|{" << TodaysDay <<"} |";
                    TodaysDay++;
                   }
                }else{
                  std::cout << "| " << TodaysDay <<"  |";
                  TodaysDay++;
                }
          }else if(LineNumbers<=35){
            if(LeapYearCheck(year) && month==2){
              if(TodaysDay<=MonthLengh[month]+1){
                if(SpecialDay!=0){
                  if(SpecialDay==1){
                    std::cout << "|(" << TodaysDay <<") |";
                    TodaysDay++;
                   }else if(SpecialDay==2){
                    std::cout << "|[" << TodaysDay <<"] |";
                    TodaysDay++;
                   }else{
                    std::cout << "|{" << TodaysDay <<"} |";
                    TodaysDay++;
                   }
                }else{
                  std::cout << "| " << TodaysDay <<"  |";
                  TodaysDay++;
                }
              }
            }else{
              if(TodaysDay<=MonthLengh[month]){
                if(SpecialDay!=0){
                  if(SpecialDay==1){
                    std::cout << "|(" << TodaysDay <<") |";
                    TodaysDay++;
                   }else if(SpecialDay==2){
                    std::cout << "|[" << TodaysDay <<"] |";
                    TodaysDay++;
                   }else{
                    std::cout << "|{" << TodaysDay <<"} |";
                    TodaysDay++;
                   }
                }else{
                  std::cout << "| " << TodaysDay <<"  |";
                  TodaysDay++;
                }
              }
            }
            
          }else{
               if(LeapYearCheck(year) && month==2){
              if(TodaysDay<=MonthLengh[month]+1){
                if(SpecialDay!=0){
                  if(SpecialDay==1){
                    std::cout << "|(" << TodaysDay <<") |";
                    TodaysDay++;
                   }else if(SpecialDay==2){
                    std::cout << "|[" << TodaysDay <<"] |";
                    TodaysDay++;
                   }else{
                    std::cout << "|{" << TodaysDay <<"} |";
                    TodaysDay++;
                   }
                }else{
                  std::cout << "| " << TodaysDay <<"  |";
                  TodaysDay++;
                }
              }
            }else{
              if(TodaysDay<=MonthLengh[month]){
                if(SpecialDay!=0){
                  if(SpecialDay==1){
                    std::cout << "|(" << TodaysDay <<") |";
                    TodaysDay++;
                   }else if(SpecialDay==2){
                    std::cout << "|[" << TodaysDay <<"] |";
                    TodaysDay++;
                   }else{
                    std::cout << "|{" << TodaysDay <<"} |";
                    TodaysDay++;
                   }
                }else{
                  std::cout << "| " << TodaysDay <<"  |";
                  TodaysDay++;
                }
              }
            }
          }
        }
      LineNumbers++;
    }
    if(TodaysDay>startDayLoop){
      std::cout << std::endl;
    } 
  }
}




void SpecialDatesPrint(int month, int MonthLengh[], SpecialDatesInfo AllSpecialDates, AddSpecialDates AddedDates, int MenuState){

  std::string SpecialTitlesGeneric[3];
  for(int i=0; i<3;i++){
    SpecialTitlesGeneric[i]=AllSpecialDates.SpecialTitles[month][i];
  }
  if(MenuState==4){
    switch(month){
      case 1:
        std::cout << "                     JANEIRO                     " << std::endl;
      break;
      case 2:
        std::cout << "                    FEVEREIRO                    " << std::endl;
      break;
      case 3:
        std::cout << "                      MARÇO                      " << std::endl;
      break;
      case 4:
        std::cout << "                      ABRIL                      " << std::endl;
      break;
      case 5:
        std::cout << "                       MAIO                      " << std::endl;
      break;
      case 6:
        std::cout << "                      JUNHO                      " << std::endl;
      break;
      case 7:
        std::cout << "                      JULHO                      " << std::endl;
      break;
      case 8:
        std::cout << "                     AGOSTO                      " << std::endl;
      case 9:
        std::cout << "                    SETEMBRO                     " << std::endl;
      break;
      case 10:
        std::cout << "                     OUTUBRO                     " << std::endl;
      break;
      case 11:
        std::cout << "                    NOVEMBRO                     " << std::endl;
      break;
      case 12:
        std::cout << "                    DEZEMBRO                     " << std::endl;
      break;
    } 
  }else if(MenuState!=2){
    std::cout << "DATAS PRÉ-DEFINIDAS:" << std::endl;
  }
  
  for(int i=0; i < 3; i++){
    if(SpecialTitlesGeneric[i]!=""){
      std::cout << "  " <<SpecialTitlesGeneric[i] << std::endl;
    }
  }
  
  int blankMonth=0;
  std::string AddSpecialGeneric[32];
  for(int i=0; i<32; i++){
    AddSpecialGeneric[i]=AddedDates.CustomSpecialTitles[month][i];
    if(AddSpecialGeneric[i]!=""){
      blankMonth++;
    }
  }
  if(blankMonth!=0){
    std::cout << "Marcações Adicionadas:" << std::endl;
  }

  for(int i=0; i < 32; i++){
    if(AddSpecialGeneric[i]!=""){
      std::cout << "  " <<AddSpecialGeneric[i] << std::endl;
    }
  }
  std::cout << "------------------------------------------------" << std::endl;
}

void NewSpecialDates(int month, int day, int MonthLengh[], AddSpecialDates &AddedDates){
  std::string NewDataTitle;
  std::cout <<"Por favor insira o Mes em que voce deseja adicionar um novo evento:"<< std::endl;
  std::cin >> month;
  while(month<=0 || month > 12){
    std::cout <<"Por favor insira uma data valida para o novo evento (Mês):"<< std::endl;
    std::cin >> month;
  }
  std::cout <<"Por favor insira o Dia em que voce deseja adicionar um novo evento:"<< std::endl;
  std::cin >> day;
  while(day<=0 || day > MonthLengh[month]){
    std::cout <<"Por favor insira uma data valida para o novo evento (Dia):"<< std::endl;
    std::cin >> day;
  }

  std::cout<< "Digite o titulo para o evento:" << std::endl;
  std::cin.ignore(1000, '\n');
  std::getline(std::cin, NewDataTitle);
  
  
  AddedDates.CustomSpecialDates[month][day]=true;
  if(AddedDates.CustomSpecialTitles[month][day]==""){
    AddedDates.CustomSpecialTitles[month][day]= std::to_string(day) + "/" + std::to_string(month) + " - " + NewDataTitle;
  }else{
    AddedDates.CustomSpecialTitles[month][day]+=(" / "+ NewDataTitle);
  }
  
}



int main(){
  SpecialDatesInfo AllSpecialDates;
  AddSpecialDates AddedDates = {};
  AllSpecialDates.SpecialDatesPre[1][1]  = true;
  AllSpecialDates.SpecialDatesPre[3][8]  = true;
  AllSpecialDates.SpecialDatesPre[4][21] = true;
  AllSpecialDates.SpecialDatesPre[5][1]  = true;
  AllSpecialDates.SpecialDatesPre[6][12] = true;
  AllSpecialDates.SpecialDatesPre[9][7]  = true;
  AllSpecialDates.SpecialDatesPre[10][12]= true;
  AllSpecialDates.SpecialDatesPre[10][15]= true;
  AllSpecialDates.SpecialDatesPre[11][2] = true;
  AllSpecialDates.SpecialDatesPre[11][15]= true;
  AllSpecialDates.SpecialDatesPre[11][20]= true;
  AllSpecialDates.SpecialDatesPre[12][24]= true;
  AllSpecialDates.SpecialDatesPre[12][25]= true;
  AllSpecialDates.SpecialDatesPre[12][31]= true;

  AllSpecialDates.SpecialTitles[1][0] ="01/01 - Confraternização Universal";
  AllSpecialDates.SpecialTitles[3][0] ="08/03 - Dia Internacional da Mulher";
  AllSpecialDates.SpecialTitles[4][0] ="21/04 - Tiradentes";
  AllSpecialDates.SpecialTitles[5][0] ="01/05 - Dia do Trabalho";
  AllSpecialDates.SpecialTitles[6][0] ="12/06 - Dia dos Namorados";
  AllSpecialDates.SpecialTitles[9][0] ="07/09 - Independência do Brasil";
  AllSpecialDates.SpecialTitles[10][0]="12/10 - Nossa Sra Aparecida";
  AllSpecialDates.SpecialTitles[10][1]="12/10 - Dia das Crianças" ;
  AllSpecialDates.SpecialTitles[10][2]="15/10 - Dia do Professor";
  AllSpecialDates.SpecialTitles[11][0]="02/11 - Finados";
  AllSpecialDates.SpecialTitles[11][1]="15/11 - Proclamação da República";
  AllSpecialDates.SpecialTitles[11][2]="20/11 - Dia da Consciência Negra";
  AllSpecialDates.SpecialTitles[12][0]="24/12 - Véspera de Natal" ;
  AllSpecialDates.SpecialTitles[12][1]="25/12 - Natal" ;
  AllSpecialDates.SpecialTitles[12][2]="31/12 - Véspera de Ano Novo";




  int MonthLengh[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day=1,month=1,year=1;
  int MenuState =0, MenuInternalState=0;
  bool firstInteraction =true;

  while (MenuState !=5){
    
    //Menu Inicial
    while(MenuState == 0){
      std::cout << R"(
          ______             __                            __                      __                  ______                     
         /      \           |  \                          |  \                    |  \                /      \    __        __    
        |  $$$$$$\  ______  | $$  ______   _______    ____| $$  ______    ______   \$$  ______       |  $$$$$$\  |  \      |  \   
        | $$   \$$ |      \ | $$ /      \ |       \  /      $$ |      \  /      \ |  \ /      \      | $$   \$$__| $$__  __| $$__ 
        | $$        \$$$$$$\| $$|  $$$$$$\| $$$$$$$\|  $$$$$$$  \$$$$$$\|  $$$$$$\| $$|  $$$$$$\     | $$     |    $$  \|    $$  \
        | $$   __  /      $$| $$| $$    $$| $$  | $$| $$  | $$ /      $$| $$   \$$| $$| $$  | $$     | $$   __ \$$$$$$$$ \$$$$$$$$
        | $$__/  \|  $$$$$$$| $$| $$$$$$$$| $$  | $$| $$__| $$|  $$$$$$$| $$      | $$| $$__/ $$     | $$__/  \  | $$      | $$   
        \$$    $$ \$$    $$| $$ \$$     \| $$  | $$ \$$    $$ \$$    $$| $$      | $$ \$$    $$     \$$    $$   \$$       \$$   
          \$$$$$$   \$$$$$$$ \$$  \$$$$$$$ \$$   \$$  \$$$$$$$  \$$$$$$$ \$$       \$$  \$$$$$$|      \$$$$$$                    
    )" << std::endl;


      std::cout  << "1. Consultar um Mês especifico"<< std::endl;
      std::cout  << "2. Consultar um Ano especifico"<< std::endl;
      std::cout  << "3. Adicionar Marcação"<< std::endl;
      std::cout  << "4. Consultar Marcações adicionadas" << std::endl;
      std::cout  << "5. Fechar" << std::endl;
      std::cin >> MenuState;

    }

    //MES
    while(MenuState == 1 ) {
      std::cout << "Insira o mes desejado:" << std::endl;
      std::cin  >> month;
      while(month<=0 || month>12){
        std::cout << "Por favor insira um mês válido:" << std::endl;
        std::cin  >> month;
      } 

      std::cout << "Insira o ano desejado:" << std::endl;
      std::cin  >> year;
      while(year<1){
        std::cout << "Por favor insira um ano válido (maior que 0):" << std::endl;
        std::cin  >> year;
      } 

      DrawMonth(month, year, MonthLengh, AllSpecialDates, AddedDates);
      SpecialDatesPrint(month, MonthLengh, AllSpecialDates,AddedDates, MenuState);
      std::cout << "1. Consultar outro mês" << std::endl;
      std::cout << "2. Adicionar Marcação" << std:: endl;
      std::cout << "3. Voltar" << std::endl;
      std::cin  >> MenuInternalState;
    
      while(MenuInternalState!=1 && MenuInternalState !=2 && MenuInternalState !=3){
        std::cout << "Por Favor Insira uma Opção valida:" << std::endl;
        std::cout << "1. Consultar outro mês" << std::endl;
        std::cout << "2. Adicionar Marcação" << std::endl;
        std::cout << "3. Voltar" << std::endl;
        std::cin  >> MenuInternalState;
      }
      if(MenuInternalState==1){

      }else if(MenuInternalState==2){
        MenuState=3;
      }else if(MenuInternalState==3){
        MenuState=0;
      }
    }
    
    //ANO
    while(MenuState == 2){
      std::cout << "Insira o Ano desejado:" << std::endl;
      std::cin  >> year;
      while(year<0){
        std::cout << "Por favor Insira um ano válido (maior que 0):" << std::endl;
        std::cin  >> year;
      }

      for(int i=1;i<=12;i++){
        DrawMonth(i, year, MonthLengh, AllSpecialDates, AddedDates);
        SpecialDatesPrint(month, MonthLengh, AllSpecialDates,AddedDates, MenuState);
      }

      std::cout  << "1.Consultar outro ano:" << std::endl;
      std::cout  << "2.Adicionar Marcação" << std:: endl;
      std::cout  << "3.Voltar" << std::endl;
      std::cin  >> MenuInternalState;

      while(MenuInternalState!=1 && MenuInternalState!=2 && MenuInternalState!=3){
        std::cout << "Por Favor Insira uma Opção valida:" << std::endl;
        std::cout  << "1.Consultar outro ano:" << std::endl;
        std::cout  << "2.Adicionar Marcação" << std:: endl;
        std::cout  << "3.Voltar" << std::endl;
        std::cin  >> MenuInternalState;
      }
      if(MenuInternalState==1){

      }else if(MenuInternalState==2){
        MenuState=3;
      }else if(MenuInternalState==3){
        MenuState=0;
      }
      
    }
    
    //adicionar marcação
    while(MenuState==3){
      std::cout << "------------------------------------------------- " << std::endl;
      NewSpecialDates(month,day,MonthLengh,AddedDates);
      std::cout  << "1.Adicionar outra Marcação" << std:: endl;
      std::cout  << "2.Voltar" << std::endl;

      std::cin >> MenuInternalState;

      if(MenuInternalState==2){
        MenuState=0;
      }else if(MenuInternalState==1){

      }
    

    }
    
    //consultar marcações
    while(MenuState==4){
      MenuInternalState=0;
      std::cout << "================================================ " << std::endl;
      for(int i=1;i<=12; i++){
        SpecialDatesPrint(i, MonthLengh, AllSpecialDates,AddedDates, MenuState);
      }
      std::cout  << "1.Adicionar Marcação" << std:: endl;
      std::cout  << "2.Voltar" << std::endl;
      std::cin >> MenuInternalState;
      while(MenuInternalState!=1 && MenuInternalState!=2){
        std::cout << "Por Favor Insira uma Opção valida:" << std::endl;
        std::cout  << "1.Adicionar Marcação" << std:: endl;
        std::cout  << "2.Voltar" << std::endl;
        std::cin >> MenuInternalState;
      }
      if(MenuInternalState==1){
        MenuState=3;
      }else{
        MenuState=0;
      }
    }
  }
  return 0;
}
