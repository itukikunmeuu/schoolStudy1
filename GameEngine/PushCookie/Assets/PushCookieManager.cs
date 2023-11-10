using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using UnityEngine;
using UnityEngine.UI;

public class PushCookieManager : MonoBehaviour
{
    /*�Q�[���I�u�W�F�N�g�ϐ�*/
    GameObject _cookie;

    /*�g��k��*/
    Vector3 _delSmall, _delBig;
    Vector3 _delR;
    /*��]*/
    Vector3 _axis;
    Quaternion _delQ;//��]�x����
    bool _isBigFlag;

    /*�N�b�L�[����*/
    GameObject _preCookie;

    // Start is called before the first frame update
    void Start()
    {
        //�Q�[���I�u�W�F�N�g�̎擾
        _cookie = GameObject.Find("Cokkie");

        //�ϐ�������
        _delSmall = new Vector3(1.6f, 1.6f,1.6f);
        _delBig = new Vector3(0.02f, 0.02f, 0.02f);
        _isBigFlag = false;
        _axis = new Vector3(0, 0, 1f);
        _delQ = Quaternion.AngleAxis(0.4f, _axis);

        /*�N�b�L�[����*/
        _preCookie = (GameObject)Resources.Load("preCookle");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void FixedUpdate()
    {
        //�g��k��
           if(_isBigFlag)
        {
            _cookie.transform.localScale += _delBig;
        }

        //��]����
     //   _cookie.transform.Rotate(0,0,1);
        _cookie.transform.rotation = _delQ * _delR;
    }
    /*�{�^�����\�b�h*/
    public void Click()
    {
        //�k��
        _cookie.transform.localScale = _delSmall;
        _isBigFlag = true;

        //�v���n�u�C���X�^���X�̍쐬
        //�����̍쐬
        float x = Random.Range(-20.0f, 20.0f);
        float z = Random.Range(-12.0f, 24.0f);

        //�v���n�u�C���X�^���X�̍쐬
        Instantiate(_preCookie, new Vector3(x, 24.0f, z), Quaternion, Euler(0, 180, 0));
    }
}
