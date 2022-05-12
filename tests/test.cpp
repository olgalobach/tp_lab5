#include <gtest/gtest.h>

#include <Account.h>
#include <Transaction.h>
TEST(Account, Test_All)
{
    Account a(1, 1000);

    EXPECT_EQ(1000, a.GetBalance());

    a.ChangeBalance(2000);

    EXPECT_EQ(2000, a.GetBalance());

    a.Lock();

    try
    {
        a.ChangeBalance(3000);
    }
    catch (const std::runtime_error &e)
    {
        std::string s1 = "already locked";
        std::string s2 = e.what();
        EXPECT_EQ(s1, s2);
    }

    try
    {
        a.Lock();
    }
    catch (const std::runtime_error &e)
    {
        std::string s1 = "at first lock the account";
        std::string s2 = e.what();
        EXPECT_EQ(s1, s2);
    }

    a.Unlock();
}