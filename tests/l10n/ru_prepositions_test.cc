#include <clocale>
#include <gtest/gtest.h>
#include "l10n/ru_prepositions.h"

using namespace Grammar;

TEST(PrepositionsTest, BasicAssertions) {
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"власти"), L"во");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"вороте"), L"в");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"флоте"), L"во");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"феерии"), L"в");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"лоб"), L"в");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"лбу"), L"во");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"мне"), L"во");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"тебе"), L"в");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"что"), L"во");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"множестве"), L"во");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"величии"), L"в");
    EXPECT_EQ(ru_get_correct_preposition_form(L"в", L"свитке"), L"в");

    EXPECT_EQ(ru_get_correct_preposition_form(L"что-нибудь", L"все_равно_что"), L"что-нибудь");
}