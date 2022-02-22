#include <string>

namespace df {

class Manager {
    private:
        std::string m_type;
        bool m_is_started;

    protected:
        void setType(std::string type);

    public:
        Manager();
        virtual ~Manager();

        std::string getType() const;

        // 0 if ok, else negative number
        virtual int startUp();
        virtual void shutDown();

        bool isStarted() const;
};

}