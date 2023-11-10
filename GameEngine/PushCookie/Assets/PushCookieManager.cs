using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using UnityEngine;
using UnityEngine.UI;

public class PushCookieManager : MonoBehaviour
{
    /*ゲームオブジェクト変数*/
    GameObject _cookie;

    /*拡大縮小*/
    Vector3 _delSmall, _delBig;
    Vector3 _delR;
    /*回転*/
    Vector3 _axis;
    Quaternion _delQ;//回転度合い
    bool _isBigFlag;

    /*クッキー落下*/
    GameObject _preCookie;

    // Start is called before the first frame update
    void Start()
    {
        //ゲームオブジェクトの取得
        _cookie = GameObject.Find("Cokkie");

        //変数初期化
        _delSmall = new Vector3(1.6f, 1.6f,1.6f);
        _delBig = new Vector3(0.02f, 0.02f, 0.02f);
        _isBigFlag = false;
        _axis = new Vector3(0, 0, 1f);
        _delQ = Quaternion.AngleAxis(0.4f, _axis);

        /*クッキー落下*/
        _preCookie = (GameObject)Resources.Load("preCookle");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void FixedUpdate()
    {
        //拡大縮小
           if(_isBigFlag)
        {
            _cookie.transform.localScale += _delBig;
        }

        //回転処理
     //   _cookie.transform.Rotate(0,0,1);
        _cookie.transform.rotation = _delQ * _delR;
    }
    /*ボタンメソッド*/
    public void Click()
    {
        //縮小
        _cookie.transform.localScale = _delSmall;
        _isBigFlag = true;

        //プレハブインスタンスの作成
        //乱数の作成
        float x = Random.Range(-20.0f, 20.0f);
        float z = Random.Range(-12.0f, 24.0f);

        //プレハブインスタンスの作成
        Instantiate(_preCookie, new Vector3(x, 24.0f, z), Quaternion, Euler(0, 180, 0));
    }
}
