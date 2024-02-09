#include <AndComponent.hpp>
#include <FalseComponent.hpp>
#include <Gate4001.hpp>
#include <Gate4011.hpp>
#include <NotComponent.hpp>
#include <TrueComponent.hpp>
#include <memory>
#include <nts/IComponent.hpp>

// std ::ostream &operator<<(std::ostream &s, nts::Tristate v)
// {
// }

int main(int argc, char const *argv[])
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

    std::cout << "Output 3: " << gate->compute(3) << std::endl;
    std::cout << "Output 4: " << gate->compute(4) << std::endl;
    std::cout << "Output 10: " << gate->compute(10) << std::endl;
    std::cout << "Output 11: " << gate->compute(11) << std::endl;
    return 0;
}
