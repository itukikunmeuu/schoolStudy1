using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class preCookie : MonoBehaviour
{

    // Update is called once per frame
    void FixedUpdate()
    {
        this.transform.position += Vector3.down / 4;//vec(0,0.1,0)

        //画面外に出たら消滅する
        if(this.transform.position.y < -32.0f)
        {
            Destroy(this.gameObject);
        }
    }
}
