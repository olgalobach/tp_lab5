#include <gtest/gtest.h>

#include <Account.h>
#include <Transaction.h>

TEST(Account, All)
{
    Account a(1, 1000);

    EXPECT_EQ(1000, a.GetBalance());
    try
    {
        a.ChangeBalance(1000);
    }
    catch (const std::runtime_error &e)
    {
        std::string s1 = "at first lock the account";
        std::string s2 = e.what();
        EXPECT_EQ(s1, s2);
    }
    a.Lock();

    a.ChangeBalance(1000);

    EXPECT_EQ(2000, a.GetBalance());

    try
    {
        a.Lock();
    }
    catch (const std::runtime_error &e)
    {
        std::string s1 = "already locked";
        std::string s2 = e.what();
        EXPECT_EQ(s1, s2);
    }
    a.Unlock();
}

TEST(TRANSACTION, All)
{
    Account a1(1, 200);
    Account a2(2, 300);
    Transaction t1;
    try
    {
        t1.Make(a1, a2, 100);;
    }
    catch (const std::invalid_argument &e){
        std::string s1 = "sum can't be negative";
        std::string s2 = e.what();
        EXPECT_EQ(s1, s2);
    }
    catch (const std::logic_error &e)
    {
        std::string s1 = "invalid action";
        std::string s2 = e.what();
        EXPECT_EQ(s1, s2);
    }
    catch (const std::runtime_error &e)
    {
        std::string s1 = "too small";
        std::string s2 = e.what();
        EXPECT_EQ(s1, s2);
    }
    t1.Make(a1, a2, 100);

    EXPECT_EQ(200, a1.GetBalance());
    EXPECT_EQ(298, a2.GetBalance());
    Transaction t2;
    t2.set_fee(300);
    EXPECT_EQ(300, t2.fee());
    EXPECT_FALSE(t2.Make(a2, a1, 100));

    Transaction t3;
    a2.Lock();
    t3.Credit(a2, 1298);
    EXPECT_EQ(a2.GetBalance(), 1596);

    EXPECT_TRUE(t2.Debit(a2, 800));
    EXPECT_FALSE(t2.Debit(a2, 800));
}