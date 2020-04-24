#include <iostream>
  const int ROCK{1}, PAPER{2}, SCISSORS{3};
int main(){
  char choice;
  int x{0};
do{
  srand(time(0));
  int computer_choice{rand()%3 +1};
  do{
    std::cout << "Enter 1 for rock, 2 for paper, 3 for scissors:";
    std::cin >> x;
  }while(x <= 0 || x > 3 );
  if(x == 1){
    std::cout << "You chose rock\n";
  }else if(x == 2){
    std::cout << "You chose paper\n";
  }else{
    std::cout <<"You chose scissors\n";
  }
  if(computer_choice == 1){
    std::cout << "AI chose rock\n";
  }else if(computer_choice == 2){
    std::cout << "AI chose paper\n";
  }else{
    std::cout <<"AI chose scissors\n";
  }

  if(computer_choice == x){
    std::cout << "tie up\n";
  }else if(computer_choice >= x){
    std::cout << "You lost after 1 rounds\n";
  }else{
    std::cout <<"You win after 1 rounds\n";
  }
  std::cout << "Do u want to continue(Y/N)?";
  std::cin >> choice;
}while(choice =='y' || choice == 'Y');
  return 0;
}
