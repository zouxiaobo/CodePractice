// 懒汉式
class CSingleton
{
    public:
    CSingleton* getInstance()
    {
        if(m_pInstance == NULL)
            m_pInstance=new CSingleton();

        return m_pInstance;
    }

    private:
    CSingleton();
    static CSingleton* m_pInstance;

};

// 饿汉式
class CSingleton
{
    public:
    CSingleton* getInstance()
    {
        return m_pInstance;
    }

    private:
    CSingleton();
    static CSingleton* m_pInstance;

};

CSingleton* CSingleton::m_pInstance=new CSingleton();