/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


TEST(PiezasTest, constructorCheck) {
  bool checkBlank=true;
  Piezas p;
  for(int i=0;i<BOARD_ROWS;i++) {
    for(int j=0;j<BOARD_COLS;j++) {
      if(p.pieceAt(i,j)!=Blank) {
        checkBlank=false;
      }
    }
  }
  ASSERT_TRUE(checkBlank);
}
TEST(PiezasTest, toggleCheck) {
  Piezas p;
  bool checkToggle=true;
  if(p.switchTurn()!=O)
  {
    checkToggle=false;
  }
  ASSERT_TRUE(checkToggle);
}
TEST(PiezasTest, resetCheck) {
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.reset();
  bool checkReset=false;
  if(p.pieceAt(2,0)==Blank && p.pieceAt(2,1)==Blank) {
    checkReset=true;
  }
  ASSERT_TRUE(checkReset);
}

TEST(PiezasTest, dropPiecenonEmptyColumn)
{
 Piezas p;
 bool check=false;
 p.dropPiece(0);
 p.dropPiece(0);
 p.dropPiece(0);
 if(p.dropPiece(0)==Blank) {
  check=true;
 }
 ASSERT_TRUE(check);
}

TEST(PiezasTest, dropPieceInValid)
{
  Piezas p;
  bool check= false;
  if(p.dropPiece(5)==Invalid)
  {
   check=true;
  }
  ASSERT_TRUE(check);
}

TEST(PiezasTest, dropPieceNormal)
{
  Piezas p;
  p.dropPiece(0);
  ASSERT_TRUE(p.pieceAt(2,0)==X);
}

TEST(PiezasTest, checkInvalidPlace)
{
  Piezas p;
  ASSERT_TRUE(p.pieceAt(2,5)==Invalid);
}

TEST(PiezasTest, gameNotOver)
{
  Piezas p;
  ASSERT_TRUE(p.gameState()==Invalid);
}

TEST(PiezasTest, gameTie)
{
  Piezas p;
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(3);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  ASSERT_TRUE(p.gameState()==Blank);
}

TEST(PiezasTest, winnerXvertical)
{
  Piezas pi;
  pi.reset(); 
  pi.dropPiece(0);
  pi.dropPiece(1);
  pi.dropPiece(2);
  pi.dropPiece(3);
  pi.dropPiece(2);
  pi.dropPiece(0);
  pi.dropPiece(2);
  pi.dropPiece(3);
  pi.dropPiece(1);
  pi.dropPiece(0);
  pi.dropPiece(3);
  pi.dropPiece(1);
  
  ASSERT_TRUE(pi.gameState()==X);
} 

TEST(PiezasTest, winnerOvertical)
{
  Piezas pi;
  pi.reset(); 
  pi.dropPiece(0);
  pi.dropPiece(1);
  pi.dropPiece(2);
  pi.dropPiece(3);
  pi.dropPiece(3);
  pi.dropPiece(1);
  pi.dropPiece(3);
  pi.dropPiece(1);
  pi.dropPiece(2);
  pi.dropPiece(2);
  pi.dropPiece(0);
  pi.dropPiece(0);
  
  ASSERT_TRUE(pi.gameState()==O);
}
 
TEST(PiezasTest, winnerHorizontal)
{
  Piezas pi;
  pi.reset(); 
  pi.dropPiece(0);
  pi.dropPiece(1);
  pi.dropPiece(2);
  pi.dropPiece(3);
  pi.dropPiece(1);
  pi.dropPiece(0);
  pi.dropPiece(2);
  pi.dropPiece(0);
  pi.dropPiece(3);
  pi.dropPiece(3);
  pi.dropPiece(1);
  pi.dropPiece(2);
  
  ASSERT_TRUE(pi.gameState()==X);
} 
