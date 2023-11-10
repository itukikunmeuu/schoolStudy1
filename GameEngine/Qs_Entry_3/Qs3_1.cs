using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry_3
{
    internal class Qs3_1
    {
        static void Main(string[] args)
        {
            /*継承*/
            //Baseを継承しているのでBaseのコンストラクタを実行してから
            //Derivedのコンストラクタが実行される。
            Console.WriteLine("【Baseのコンストラクタ語にDerivedのコンストラクタが実行】");
            Derivied x = new Derivied();


            //Baseを継承しているので、Baseのメソッドが使える
            Console.WriteLine("【Baseを継承しているので、Baseのメソッドが使える】");
            x.Show();

            //派生クラス内で、基本クラスのメソッドを使える
            Console.WriteLine("【派生クラス内で、基本クラスのメソッドを使える】");
            x.ShowPlus();

            //基本クラスの変数で派生クラスのインスタンスを扱える
            //ただし、基本クラスのメンバーしか使えない。
            Console.WriteLine("【基本クラスの変数で派生クラスのインスタンスを扱える】");
            Base y = x;
            y.Show(); //親の変数のまま、親のメソッドは使える

        }
    }

    /*継承*/
    //既に存在するクラスの機能を新しいクラスに引き継ぐ機能
    //継承するクラスを基本クラス。継承先を派生クラスと呼びます
    //C#ではC++と違い、多重継承が禁止されています(C++でもしないほうが無難)
    public class Base//親クラス
    {
        public Base()
        {
            Console.WriteLine("基本クラスのコンストラクタ");
        }
        public void Show()
        {
            Console.WriteLine("Hello");
        }
    }
    //派生クラス
    public class Derivied : Base 
    {
        public Derivied() 
        {
            Console.WriteLine("派生クラスのコンストラクタ");
        }

        public void ShowPlus()
        {
            Show();
            Console.WriteLine("Hello2");
        }
    }
}
