//  Created by William McCarthy on 192//20.
//  Copyright © 2020 William McCarthy. All rights reserved.
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXOP 100  /* max size of operand/operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100
#define MATHNAME 'a'

size_t sp = 0;      // aka unsigned long -- printf using %zu
double val[MAXVAL]; // stack of values

char buf[BUFSIZ];
size_t bufp = 0;

int getch_(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
void ungetch_(int c) {
  if (bufp >= BUFSIZ) {
    fprintf(stderr, "ungetch: too many characters\n");
    return;
  }
  buf[bufp++] = c;
}
int getop(char *s) {
  int i, c;
  while ((s[0] = c = getch_()) == ' ' || c == '\t') {
  } // skip whitespace
  s[1] = '\0';
  i = 0;
  if(islower(c)){
    while(islower(s[++i] = c = getch_())){ }
    s[i] = '\0';
    if(c != EOF){ungetch_(c);}
    if(strlen(s) > 0){ return MATHNAME;}
  }
  if (!isdigit(c) && c != '.') {
    return c;
  } // if not a digit, return
  if(isdigit(c)){
    while(isdigit(s[++i] = c = getch_())){}
  }

  if (c == '.') { // get digits after decimal (if any)
    while (isdigit(s[++i] = c = getch_())) {}
  }
  s[i] = '\0';
  if (c != EOF) {
    ungetch_(c);
  }
  return NUMBER; // return type is NUMBER, number stored in s
}

double pop(void) {
  if (sp == 0) {
    fprintf(stderr, "stack underflow\n");
    return 0.0;
  }
  return val[--sp];
}

void push(double f) {
  if (sp == MAXVAL) {
    fprintf(stderr, "stack overflow -- can't push %g\n", f);
    return;
  }
  val[sp++] = f;
}
void swap(void) {
  double s;
  int i;
  i = sp - 1;
  s = val[i - 1];
  val[i - 1] = val[i];
  val[i] = s;
}
void mathFunction(char *s) { // exercise 4.5
  double op2;
  if (strcmp(s, "sin") == 0) {
    push(sin(pop()));
  } else if (strcmp(s, "exp") == 0) {
    push(exp(pop()));
  } else if (strcmp(s, "pow") == 0) {
    op2 = pop();
    push(pow(pop(), op2));
  } else {
    printf("error:unknown %s\n", s);
  }
}
void rpn(void) {
  int type, var = 0;
  double op2, v;
  char s[BUFSIZ];
  double variable[26];
  for (int i = 0; i < 26; i++) { variable[i] = 0.0; }
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case '\n':
      v = pop();
      printf("\t%.8g\n", pop());
      break;
    case NUMBER:
      push(atof(s));
      break;
    case MATHNAME: // exercise 4.5
      mathFunction(s);
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      push(-(pop() - pop()));
      break;
    case '/':
      if ((op2 = pop()) == 0.0) {
        fprintf(stderr, "divide by zero\n");
        break;
      }
      push(pop() / op2);
      break;
    case '%': // excersice 4.3
      if ((op2 = pop()) == 0.0) {
        fprintf(stderr, "error, modulus by zero");
        break;
      }
      push(fmod(pop(), op2));
      break;
    case '?': // exercise 4.4
      op2 = pop();
      printf("\t%.8g\n", op2);
      push(op2);
      break;
    case '$': // exercise 4.4
      op2 = pop();
      push(op2);
      push(op2);
      break;
    case '@': // exercise 4.4
      swap();
      break;
    case '!': // exercise 4.4
      sp = 0;
      break;
    case '=': // exercise 4.6
      pop();
      if (var >= 'A' && var <= 'Z')
        variable[var - 'A'] = pop();
      else
        printf("error: no variable");
      break;
    default:
      if (type >= 'A' && type <= 'Z') {
        push(variable[type - 'A']);
      } else if (type == 'v') {
        push(v);
      } else {
        fprintf(stderr, "unknown command %s\n", s);
        break;
      }
    }
    var = type;
  }
}
int main(int argc, const char *argv[]) {
  rpn();

  return 0;
}
