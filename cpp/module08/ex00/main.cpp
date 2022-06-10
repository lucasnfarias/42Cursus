/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:48:04 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/09 21:10:40 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>
#include <deque>
#include <list>

static void enterToContinue()
{
  std::cout << "\nPress enter to continue...\n";
  std::cin.ignore();
}

static void vectorTest()
{
  std::vector<int> vect;

  vect.push_back(1);
  vect.push_back(5);
  vect.push_back(42);
  vect.push_back(-1);
  vect.push_back(2333232);

  std::cout << "##################" << std::endl;
  std::cout << "# 1. VECTOR TEST #" << std::endl;
  std::cout << "##################\n"
            << std::endl;

  for (size_t i = 0; i < vect.size(); i++)
  {
    std::cout
        << "vect["
        << i
        << "] = "
        << vect[i] << std::endl;
  }

  std::cout << "\n@ 1.a easyfind value 5\n" << std::endl;
  std::vector<int>::iterator elementFound = easyfind(vect, 5);
  std::cout
      << "-> Found value "
      << *elementFound
      << " on vector at index "
      << std::distance(vect.begin(), elementFound)
      << std::endl;

  std::cout << "\n@ 1.b easyfind value 321 (not found error)\n" << std::endl;
  try
  {
    easyfind(vect, 321);
  }
  catch (const std::exception &e)
  {
    std::cerr << "-> " << e.what() << '\n';
  }

{
  std::cout << "\n@ 1.c easyfind value -1\n" << std::endl;
  std::vector<int>::iterator elementFound = easyfind(vect, -1);
  std::cout
      << "-> Found value "
      << *elementFound
      << " on vector at index "
      << std::distance(vect.begin(), elementFound)
      << std::endl;
}

  enterToContinue();
}

static void dequeTest()
{
  std::deque<int> deq;

  deq.push_back(20000);
  deq.push_back(123);
  deq.push_back(-84);
  deq.push_back(-12);
  deq.push_back(2);

  std::cout << "#################" << std::endl;
  std::cout << "# 2. DEQUE TEST #" << std::endl;
  std::cout << "#################\n"
            << std::endl;

  for (size_t i = 0; i < deq.size(); i++)
  {
    std::cout
        << "deq["
        << i
        << "] = "
        << deq[i] << std::endl;
  }

  std::cout << "\n@ 2.a easyfind value 2\n" << std::endl;
  std::deque<int>::iterator elementFound = easyfind(deq, 2);
  std::cout
      << "-> Found value "
      << *elementFound
      << " on deque at index "
      << std::distance(deq.begin(), elementFound)
      << std::endl;

  std::cout << "\n@ 2.b easyfind value 321 (not found error)\n" << std::endl;
  try
  {
    easyfind(deq, 321);
  }
  catch (const std::exception &e)
  {
    std::cerr << "-> " << e.what() << '\n';
  }

{
  std::cout << "\n@ 2.c easyfind value 20000\n" << std::endl;
  std::deque<int>::iterator elementFound = easyfind(deq, 20000);
  std::cout
      << "-> Found value "
      << *elementFound
      << " on deque at index "
      << std::distance(deq.begin(), elementFound)
      << std::endl;
}

  enterToContinue();
}

static void listTest()
{
  std::list<int> littleList;

  littleList.push_back(21);
  littleList.push_back(32);
  littleList.push_back(111111111);
  littleList.push_back(-2122221223);
  littleList.push_back(0);

  std::cout << "################" << std::endl;
  std::cout << "# 3. LIST TEST #" << std::endl;
  std::cout << "################\n"
            << std::endl;

  for (
    std::list<int>::iterator listBeginning = littleList.begin();
    listBeginning != littleList.end();
    listBeginning++)
  {
    std::cout
        << "littleList = "
        << *listBeginning << std::endl;
  }

  std::cout << "\n@ 3.a easyfind value -2122221223\n" << std::endl;
  std::list<int>::iterator elementFound = easyfind(littleList, -2122221223);
  std::cout
      << "-> Found value "
      << *elementFound
      << " on list at index "
      << std::distance(littleList.begin(), elementFound)
      << std::endl;

  std::cout << "\n@ 3.b easyfind value 321 (not found error)\n" << std::endl;
  try
  {
    easyfind(littleList, 321);
  }
  catch (const std::exception &e)
  {
    std::cerr << "-> " << e.what() << '\n';
  }

{
  std::cout << "\n@ 3.c easyfind value 0\n" << std::endl;
  std::list<int>::iterator elementFound = easyfind(littleList, 0);
  std::cout
      << "-> Found value "
      << *elementFound
      << " on list at index "
      << std::distance(littleList.begin(), elementFound)
      << std::endl;
}
  enterToContinue();
}

static void setTest()
{
  std::set<int> setinho;

  setinho.insert(11);
  setinho.insert(51);
  setinho.insert(422);
  setinho.insert(-13);
  setinho.insert(24);

  std::cout << "###############" << std::endl;
  std::cout << "# 4. SET TEST #" << std::endl;
  std::cout << "###############\n"
            << std::endl;

  for (
    std::set<int>::iterator setBeginning = setinho.begin();
    setBeginning != setinho.end();
    setBeginning++)
  {
    std::cout
        << "setinho = "
        << *setBeginning << std::endl;
  }

  std::cout << "\n@ 4.a easyfind value -13\n" << std::endl;
  std::set<int>::iterator elementFound = easyfind(setinho, -13);
  std::cout
      << "-> Found value "
      << *elementFound
      << " on set at index "
      << std::distance(setinho.begin(), elementFound)
      << std::endl;

  std::cout << "\n@ 4.b easyfind value 321 (not found error)\n" << std::endl;
  try
  {
    easyfind(setinho, 321);
  }
  catch (const std::exception &e)
  {
    std::cerr << "-> " << e.what() << '\n';
  }

{
  std::cout << "\n@ 4.c easyfind value 51\n" << std::endl;
  std::set<int>::iterator elementFound = easyfind(setinho, 51);
  std::cout
      << "-> Found value "
      << *elementFound
      << " on set at index "
      << std::distance(setinho.begin(), elementFound)
      << std::endl;
}
}

int main()
{
  vectorTest();
  dequeTest();
  listTest();
  setTest();
}
