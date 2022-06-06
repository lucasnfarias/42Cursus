/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:48:04 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/06 20:02:38 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>
#include <deque>
#include <list>

static void vectorTest()
{
  std::vector<int> deq;

  deq.push_back(1);
  deq.push_back(5);
  deq.push_back(42);
  deq.push_back(-1);
  deq.push_back(2333232);

  std::cout << "###############" << std::endl;
  std::cout << "# 1. VECTOR TEST #" << std::endl;
  std::cout << "###############\n"
            << std::endl;

  for (size_t i = 0; i < deq.size(); i++)
  {
    std::cout
        << "deq["
        << i
        << "] = "
        << deq[i] << std::endl;
  }

  std::cout << "\n@ 1.a easyfind value 5" << std::endl;
  try
  {
    std::vector<int>::iterator elementFound = easyfind(deq, 5);
    std::cout
        << "deq["
        << std::distance(deq.begin(), elementFound)
        << "] = "
        << *elementFound
        << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

static void dequeTest()
{
  std::deque<int> deq;

  deq.push_back(1);
  deq.push_back(5);
  deq.push_back(42);
  deq.push_back(-1);
  deq.push_back(2333232);

  std::cout << "###############" << std::endl;
  std::cout << "# 2. DEQUE TEST #" << std::endl;
  std::cout << "###############\n"
            << std::endl;

  for (size_t i = 0; i < deq.size(); i++)
  {
    std::cout
        << "deq["
        << i
        << "] = "
        << deq[i] << std::endl;
  }
}

static void listTest()
{
  std::list<int> littleList;

  littleList.push_back(1);
  littleList.push_back(5);
  littleList.push_back(42);
  littleList.push_back(-1);
  littleList.push_back(2333232);

  std::cout << "###############" << std::endl;
  std::cout << "# 3. LIST TEST #" << std::endl;
  std::cout << "###############\n"
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
}

static void setTest()
{
  std::set<int> setinho;

  setinho.insert(1);
  setinho.insert(5);
  setinho.insert(42);
  setinho.insert(-1);
  setinho.insert(2333232);

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
}

int main()
{
  vectorTest();
  dequeTest();
  listTest();
  setTest();
}
