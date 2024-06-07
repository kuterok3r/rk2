#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "house.h"

class HouseMock : public House{
    public:
    HouseMock(int stairs, int lat, int longitude): House(stairs, lat, longitude){}
    MOCK_CONST_METHOD0(getStairs, int());
    MOCK_METHOD1(accept, void(Visitor));
};

TEST(HouseMock, firstTest){
    HouseMock House(5, 6, 7);
    EXPECT_CALL(House, getStairs()).Times(1);
    House.getStairs();
}
TEST(House, secondTest){
    House House(1, 2, 54);
    EXPECT_CALL(House, getStairs()).Times(1);
    EXPECT_EQ(House.getStairs(), 1);
}
TEST(House, thirdTest){
    Visitor *visitor;
    House House(5, 6, 7);
    EXPECT_CALL(House, accept()).Times(1);
    House.accept(visitor);
}