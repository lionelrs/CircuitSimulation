#include <AndComponent.hpp>
#include <FalseComponent.hpp>
#include <Gate4001.hpp>
#include <Gate4011.hpp>
#include <Gate4030.hpp>
#include <Gate4069.hpp>
#include <Gate4071.hpp>
#include <Gate4081.hpp>
#include <NandComponent.hpp>
#include <NorComponent.hpp>
#include <NotComponent.hpp>
#include <OrComponent.hpp>
#include <TrueComponent.hpp>
#include <XorComponent.hpp>
#include <gtest/gtest.h>
#include <nts/IComponent.hpp>

TEST(ComponentTest, TrueComponentOutputsTrue)
{
    nts::TrueComponent trueComp;
    EXPECT_EQ(trueComp.compute(1), nts::Tristate::True);
}

// Test for FalseComponent
TEST(ComponentTest, FalseComponentOutputsFalse)
{
    nts::FalseComponent falseComp;
    EXPECT_EQ(falseComp.compute(1), nts::Tristate::False);
}

// Test for NotComponent
TEST(ComponentTest, NotComponentInvertsInput)
{
    nts::NotComponent notComp;
    nts::TrueComponent trueInput;
    nts::FalseComponent falseInput;

    notComp.setLink(1, trueInput, 1); // Assuming pin 1 is the input pin for NotComponent
    EXPECT_EQ(notComp.compute(2), nts::Tristate::False); // Assuming pin 2 is the output pin

    notComp.setLink(1, falseInput, 1);
    EXPECT_EQ(notComp.compute(2), nts::Tristate::True);
}

// Test for AndComponent
TEST(ComponentTest, AndComponentOutputsCorrectly)
{
    nts::AndComponent andComp;
    nts::TrueComponent trueInput;
    nts::FalseComponent falseInput;

    // True AND True = True
    andComp.setLink(1, trueInput, 1); // Assuming pin 1 is input A for AndComponent
    andComp.setLink(2, trueInput, 1); // Assuming pin 2 is input B
    EXPECT_EQ(andComp.compute(3), nts::Tristate::True); // Assuming pin 3 is the output pin

    // True AND False = False
    andComp.setLink(1, trueInput, 1);
    andComp.setLink(2, falseInput, 1);
    EXPECT_EQ(andComp.compute(3), nts::Tristate::False);

    // False AND False = False
    andComp.setLink(1, falseInput, 1);
    andComp.setLink(2, falseInput, 1);
    EXPECT_EQ(andComp.compute(3), nts::Tristate::False);
}

// Test for NandComponent
TEST(ComponentTest, NandComponentOutputsCorrectly)
{
    nts::NandComponent NandComp;
    nts::TrueComponent trueInput;
    nts::FalseComponent falseInput;

    // True Nand True = False
    NandComp.setLink(1, trueInput, 1); // Assuming pin 1 is input A for NandComponent
    NandComp.setLink(2, trueInput, 1); // Assuming pin 2 is input B
    EXPECT_EQ(NandComp.compute(3), nts::Tristate::False); // Assuming pin 3 is the output pin

    // True Nand False = True
    NandComp.setLink(1, trueInput, 1);
    NandComp.setLink(2, falseInput, 1);
    EXPECT_EQ(NandComp.compute(3), nts::Tristate::True);

    // False Nand True = True
    NandComp.setLink(1, falseInput, 1);
    NandComp.setLink(2, trueInput, 1);
    EXPECT_EQ(NandComp.compute(3), nts::Tristate::True);

    // False Nand False = True
    NandComp.setLink(1, falseInput, 1);
    NandComp.setLink(2, falseInput, 1);
    EXPECT_EQ(NandComp.compute(3), nts::Tristate::True);
}

// Test for OrComponent
TEST(ComponentTest, OrComponentOutputsCorrectly)
{
    nts::OrComponent OrComp;
    nts::TrueComponent trueInput;
    nts::FalseComponent falseInput;

    // True Or True = True
    OrComp.setLink(1, trueInput, 1); // Assuming pin 1 is input A for OrComponent
    OrComp.setLink(2, trueInput, 1); // Assuming pin 2 is input B
    EXPECT_EQ(OrComp.compute(3), nts::Tristate::True); // Assuming pin 3 is the output pin

    // True Or False = False
    OrComp.setLink(1, trueInput, 1);
    OrComp.setLink(2, falseInput, 1);
    EXPECT_EQ(OrComp.compute(3), nts::Tristate::True);

    // False Or False = False
    OrComp.setLink(1, falseInput, 1);
    OrComp.setLink(2, falseInput, 1);
    EXPECT_EQ(OrComp.compute(3), nts::Tristate::False);
}

// Test for XorComponent
TEST(ComponentTest, XorComponentOutputsCorrectly)
{
    nts::XorComponent XorComp;
    nts::TrueComponent trueInput;
    nts::FalseComponent falseInput;

    // True Xor True = False
    XorComp.setLink(1, trueInput, 1); // Assuming pin 1 is input A for XorComponent
    XorComp.setLink(2, trueInput, 1); // Assuming pin 2 is input B
    EXPECT_EQ(XorComp.compute(3), nts::Tristate::False); // Assuming pin 3 is the output pin

    // True Xor False = True
    XorComp.setLink(1, trueInput, 1);
    XorComp.setLink(2, falseInput, 1);
    EXPECT_EQ(XorComp.compute(3), nts::Tristate::True);

    // False Xor False = False
    XorComp.setLink(1, falseInput, 1);
    XorComp.setLink(2, falseInput, 1);
    EXPECT_EQ(XorComp.compute(3), nts::Tristate::False);
}

// Test for NorComponent
TEST(ComponentTest, NorComponentOutputsCorrectly)
{
    nts::NorComponent NorComp;
    nts::TrueComponent trueInput;
    nts::FalseComponent falseInput;

    // True Nor True = False
    NorComp.setLink(1, trueInput, 1); // Assuming pin 1 is input A for NorComponent
    NorComp.setLink(2, trueInput, 1); // Assuming pin 2 is input B
    EXPECT_EQ(NorComp.compute(3), nts::Tristate::False); // Assuming pin 3 is the output pin

    // True Nor False = True
    NorComp.setLink(1, trueInput, 1);
    NorComp.setLink(2, falseInput, 1);
    EXPECT_EQ(NorComp.compute(3), nts::Tristate::False);

    // False Nor False = False
    NorComp.setLink(1, falseInput, 1);
    NorComp.setLink(2, falseInput, 1);
    EXPECT_EQ(NorComp.compute(3), nts::Tristate::True);
}

// Test for Gate4001
TEST(ComponentTest, Gate4001OutputsCorrectly)
{
    std::unique_ptr<nts::IComponent> gate = std::make_unique<nts::Gate4001>();
    std::unique_ptr<nts::IComponent> in1 = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> in2 = std::make_unique<nts::FalseComponent>();

    gate->setLink(1, *in1, 1);
    gate->setLink(2, *in1, 1);
    gate->setLink(5, *in1, 1);
    gate->setLink(6, *in2, 1);
    gate->setLink(8, *in2, 1);
    gate->setLink(9, *in1, 1);
    gate->setLink(12, *in2, 1);
    gate->setLink(13, *in2, 1);

    // Output 3 = False
    EXPECT_EQ(gate->compute(3), nts::Tristate::False);

    // Output 4 = False
    EXPECT_EQ(gate->compute(4), nts::Tristate::False);

    // Output 10 = False
    EXPECT_EQ(gate->compute(10), nts::Tristate::False);

    // Output 11 = True
    EXPECT_EQ(gate->compute(11), nts::Tristate::True);
}

// Test for Gate4011
TEST(ComponentTest, Gate4011OutputsCorrectly)
{
    std::unique_ptr<nts::IComponent> gate = std::make_unique<nts::Gate4011>();
    std::unique_ptr<nts::IComponent> in1 = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> in2 = std::make_unique<nts::FalseComponent>();

    gate->setLink(1, *in1, 1);
    gate->setLink(2, *in1, 1);
    gate->setLink(5, *in1, 1);
    gate->setLink(6, *in2, 1);
    gate->setLink(8, *in2, 1);
    gate->setLink(9, *in1, 1);
    gate->setLink(12, *in2, 1);
    gate->setLink(13, *in2, 1);

    // Output 3 = False
    EXPECT_EQ(gate->compute(3), nts::Tristate::False);

    // Output 4 = True
    EXPECT_EQ(gate->compute(4), nts::Tristate::True);

    // Output 10 = True
    EXPECT_EQ(gate->compute(10), nts::Tristate::True);

    // Output 11 = True
    EXPECT_EQ(gate->compute(11), nts::Tristate::True);
}

// Test for Gate4030
TEST(ComponentTest, Gate4030OutputsCorrectly)
{
    std::unique_ptr<nts::IComponent> gate = std::make_unique<nts::Gate4030>();
    std::unique_ptr<nts::IComponent> in1 = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> in2 = std::make_unique<nts::FalseComponent>();

    gate->setLink(1, *in1, 1);
    gate->setLink(2, *in1, 1);
    gate->setLink(5, *in1, 1);
    gate->setLink(6, *in2, 1);
    gate->setLink(8, *in2, 1);
    gate->setLink(9, *in1, 1);
    gate->setLink(12, *in2, 1);
    gate->setLink(13, *in2, 1);

    // Output 3 = False
    EXPECT_EQ(gate->compute(3), nts::Tristate::False);

    // Output 4 = True
    EXPECT_EQ(gate->compute(4), nts::Tristate::True);

    // Output 10 = True
    EXPECT_EQ(gate->compute(10), nts::Tristate::True);

    // Output 11 = False
    EXPECT_EQ(gate->compute(11), nts::Tristate::False);
}

// Test for Gate4069
TEST(ComponentTest, Gate4069OutputsCorrectly)
{
    std::unique_ptr<nts::IComponent> gate = std::make_unique<nts::Gate4069>();
    std::unique_ptr<nts::IComponent> in1 = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> in2 = std::make_unique<nts::FalseComponent>();

    gate->setLink(1, *in1, 1);
    gate->setLink(3, *in1, 1);
    gate->setLink(5, *in1, 1);
    gate->setLink(9, *in2, 1);
    gate->setLink(11, *in2, 1);
    gate->setLink(13, *in2, 1);

    // Output 2 = False
    EXPECT_EQ(gate->compute(2), nts::Tristate::False);

    // Output 4 = False
    EXPECT_EQ(gate->compute(4), nts::Tristate::False);

    // Output 6 = False
    EXPECT_EQ(gate->compute(6), nts::Tristate::False);

    // Output 8 = True
    EXPECT_EQ(gate->compute(8), nts::Tristate::True);

    // Output 10 = True
    EXPECT_EQ(gate->compute(10), nts::Tristate::True);

    // Output 12 = True
    EXPECT_EQ(gate->compute(12), nts::Tristate::True);
}

// Test for Gate4071
TEST(ComponentTest, Gate4071OutputsCorrectly)
{
    std::unique_ptr<nts::IComponent> gate = std::make_unique<nts::Gate4071>();
    std::unique_ptr<nts::IComponent> in1 = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> in2 = std::make_unique<nts::FalseComponent>();

    gate->setLink(1, *in1, 1);
    gate->setLink(2, *in1, 1);
    gate->setLink(5, *in1, 1);
    gate->setLink(6, *in2, 1);
    gate->setLink(8, *in2, 1);
    gate->setLink(9, *in1, 1);
    gate->setLink(12, *in2, 1);
    gate->setLink(13, *in2, 1);

    // Output 3 = True
    EXPECT_EQ(gate->compute(3), nts::Tristate::True);

    // Output 4 = True
    EXPECT_EQ(gate->compute(4), nts::Tristate::True);

    // Output 10 = True
    EXPECT_EQ(gate->compute(10), nts::Tristate::True);

    // Output 11 = False
    EXPECT_EQ(gate->compute(11), nts::Tristate::False);
}

// Test for Gate4081
TEST(ComponentTest, Gate4081OutputsCorrectly)
{
    std::unique_ptr<nts::IComponent> gate = std::make_unique<nts::Gate4081>();
    std::unique_ptr<nts::IComponent> in1 = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> in2 = std::make_unique<nts::FalseComponent>();

    gate->setLink(1, *in1, 1);
    gate->setLink(2, *in1, 1);
    gate->setLink(5, *in1, 1);
    gate->setLink(6, *in2, 1);
    gate->setLink(8, *in2, 1);
    gate->setLink(9, *in1, 1);
    gate->setLink(12, *in2, 1);
    gate->setLink(13, *in2, 1);

    // Output 3 = True
    EXPECT_EQ(gate->compute(3), nts::Tristate::True);

    // Output 4 = False
    EXPECT_EQ(gate->compute(4), nts::Tristate::False);

    // Output 10 = False
    EXPECT_EQ(gate->compute(10), nts::Tristate::False);

    // Output 11 = False
    EXPECT_EQ(gate->compute(11), nts::Tristate::False);
}