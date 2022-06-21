/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:40:03 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/14 20:14:24 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

static void enterToContinue()
{
  std::cout << "\nPress enter to continue...\n";
  std::cin.ignore();
}

static void subjectsDefaultTests()
{
  std::cout << "\n#################" << std::endl;
  std::cout << "# SUBJECTS TEST #" << std::endl;
  std::cout << "#################\n" << std::endl;

  {
  std::cout << "\n# DEQUE TEST #\n" << std::endl;

  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite)
  {
  std::cout << *it << std::endl;
  ++it;
  }
  std::stack<int> s(mstack);
  enterToContinue();
 }

  {
  std::cout << "\n# LIST TEST #\n" << std::endl;

  MutantStack<int, std::list<int> > mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int, std::list<int> >::iterator it = mstack.begin();
  MutantStack<int, std::list<int> >::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite)
  {
  std::cout << *it << std::endl;
  it++;
  }
  std::stack<int, std::list<int> > s(mstack);
  enterToContinue();
 }

 {
  std::cout << "\n# VECTOR TEST #\n" << std::endl;

  MutantStack<int, std::vector<int> > mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
  MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite)
  {
  std::cout << *it << std::endl;
  it++;
  }
  std::stack<int, std::vector<int> > s(mstack);
  enterToContinue();
 }
}

static void differentTypesTests()
{
  std::cout << "\n##############" << std::endl;
  std::cout << "# TYPES TEST #" << std::endl;
  std::cout << "##############\n" << std::endl;

  {
    std::cout << "\n# STRING TEST (and copy constructor) #\n" << std::endl;

    MutantStack<std::string, std::vector<std::string> > mstack;

    mstack.push("Mads Mikelsen");
    mstack.push("42");
    std::cout << "Element on top of stack: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    std::cout << "\n@ Printing original stack...\n" << std::endl;
    mstack.push("Hello World!");
    mstack.push("Don't Panic");
    mstack.push("The End.");
    mstack.push("maybe not...");

    MutantStack<std::string, std::vector<std::string> >::iterator it = mstack.begin();
    MutantStack<std::string, std::vector<std::string> >::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
      std::cout << *it << std::endl;
      it++;
    }

    std::cout << "\n@ Printing mutantStack copied...\n" << std::endl;

    MutantStack<std::string, std::vector<std::string> > copyMstack(mstack);
    MutantStack<std::string, std::vector<std::string> >::iterator copyIt = copyMstack.begin();
    MutantStack<std::string, std::vector<std::string> >::iterator copyIte = copyMstack.end();

    ++copyIt;
    --copyIt;

    while (copyIt != copyIte)
    {
      std::cout << *copyIt << std::endl;
      copyIt++;
    }

    std::cout << "\n@ Add '!!!' to the original stack and print it...\n" << std::endl;
    mstack.push("!!!");

    it = mstack.begin();
    ite = mstack.end();
    while (it != ite)
    {
      std::cout << *it << std::endl;
      it++;
    }

    std::cout << "\n@ Printing mutantStack copied...(not modified)\n" << std::endl;

    copyIt = copyMstack.begin();
    copyIte = copyMstack.end();
    while (copyIt != copyIte)
    {
      std::cout << *copyIt << std::endl;
      copyIt++;
    }
    enterToContinue();
  }

  {
    std::cout << "\n# CHAR TEST (and reverse iterator) #\n" << std::endl;

    MutantStack<char, std::vector<char> > mstack;
    mstack.push('!');
    mstack.push('@');
     std::cout << "Element on top of stack: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push('e');
    mstack.push('c');
    mstack.push('i');
    mstack.push('N');
    MutantStack<char, std::vector<char> >::reverse_iterator it = mstack.rbegin();
    MutantStack<char, std::vector<char> >::reverse_iterator ite = mstack.rend();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    it++;
    }
    std::stack<char, std::vector<char> > s(mstack);
    enterToContinue();
  }
}

int main()
{
  subjectsDefaultTests();
  differentTypesTests();
}
