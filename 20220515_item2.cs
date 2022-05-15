using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class item2 : MonoBehaviour
{
    FireBall fireball;
    // Start is called before the first frame update
    void Start()
    {
        fireball = GameObject.FindWithTag("FireBall").GetComponent<FireBall>();//FireBall 스크립트에서 변수 가져오기
    }

    // Update is called once per frame
    void Update()
    {

    }

    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.tag == "Umbrella")//우산에 닿으면 체력 증가
        {
            fireball.Current_HP += fireball.item_heal;
            fireball.Current_HP = Mathf.Min(fireball.Current_HP, fireball.FireBall_HP);//최대 HP를 넘길 수 없음
            Destroy(gameObject);//객체 파괴
        }
        else if (other.gameObject.tag == "Ground")
        {
            Destroy(gameObject);//객체 파괴
        }
    }
}
