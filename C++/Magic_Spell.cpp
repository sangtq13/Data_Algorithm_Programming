#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */
    if (typeid(*spell) == typeid(Fireball)) {
        dynamic_cast<Fireball*>(spell)->revealFirepower();
    }
    else if (typeid(*spell) == typeid(Frostbite)) {
        dynamic_cast<Frostbite*>(spell)->revealFrostpower();
    }
    else if (typeid(*spell) == typeid(Thunderstorm)) {
        dynamic_cast<Thunderstorm*>(spell)->revealThunderpower();
    }
    else if (typeid(*spell) == typeid(Waterbolt)) {
        dynamic_cast<Waterbolt*>(spell)->revealWaterpower();
    }
    else {
        string s = spell->revealScrollName();
        string t = SpellJournal::journal;
        int m = s.size();
        int n = t.size();
        int arr[m+1][n+1];
        for (int i=0; i<=m; ++i) arr[i][0] = 0;
        for (int i=0; i<=n; ++i) arr[0][i] = 0;

        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (s[i-1] == t[j-1]) {
                    arr[i][j] = 1 + arr[i-1][j-1];
                }
                else {
                    arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
                }
            }
        }
        cout << arr[m][n] << "\n";
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
