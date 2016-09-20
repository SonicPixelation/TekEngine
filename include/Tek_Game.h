#ifndef TEK_GAME_H
#define TEK_GAME_H


class Tek_Game
{
    public:
        Tek_Game(const char* appId, const char* appVersion);
    protected:
    private:
        const char* _appId;
        const char* _appVersion;
};

#endif // TEK_GAME_H
