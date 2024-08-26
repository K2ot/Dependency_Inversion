#include <iostream>
#include <fstream>

#include <string>


class ILogger
{
public:
    virtual ~ILogger() {}
    virtual void logMessage(const std::string& message) = 0;
};


class FileLogger : public ILogger
{
public:
    void logMessage(const std::string& message) override {
        std::ofstream logFile("log.txt", std::ios::app);
        logFile << message << std::endl;
        logFile.close();
    }
};


class ConsoleLogger : public ILogger
{
public:
    void logMessage(const std::string& message) override
    {
        std::cout << message << std::endl;
    }
};

class Application
{
private:
    ILogger& logger;

public:
    Application(ILogger& logger) : logger(logger) {}

    void run()
    {
        logger.logMessage("Application started successfully.");
        // ...
        logger.logMessage("Application is running.");
        // ...
        logger.logMessage("Application ended successfully.");
    }
};


int main()
{
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;

    Application app1(consoleLogger);
    Application app2(fileLogger);

    app1.run();
    app2.run();

    return 0;
}