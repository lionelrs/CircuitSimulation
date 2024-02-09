#ifndef GATE4011_HPP_
#define GATE4011_HPP_

#include <NandComponent.hpp>
#include <array>
#include <memory>
#include <nts/AComponent.hpp>
#include <vector>

namespace nts {
class Gate4011 : public AComponent {
    public:
        Gate4011();
        ~Gate4011() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        std::unordered_map<std::size_t, std::size_t> _outToGate;
        std::unordered_map<std::size_t, std::size_t> _inToGateIn;
        std::vector<std::unique_ptr<IComponent>> nandGates;
};

}
#endif // !GATE4011_HPP_