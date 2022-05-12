using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UmbrellaMgr : MonoBehaviour
{
    PersonMov personMove;
    GameObject person;
    Vector3 target;

    // Start is called before the first frame update
    void Start()
    {
        transform.Rotate(new Vector3(0f,0f,-45f));//우산 회전
        person = GameObject.Find("Person");
        personMove = GameObject.FindWithTag("Player").GetComponent<PersonMov>();//PersonMov 스크립트에서 변수 가져오기
    }

    // Update is called once per frame
    void Update()
    {
        UmbrellaPosition();//우산의 위치
    }
    void UmbrellaPosition()//우산의 위치
    {
        if(personMove.left)
        {
            gameObject.GetComponent<Transform>().position += Vector3.left * personMove.speed * Time.deltaTime;
        }else if (personMove.right)
        {
            gameObject.GetComponent<Transform>().position += Vector3.right * personMove.speed * Time.deltaTime;
        }
    }
    void OnCollisionEnter2D(Collision2D other)//충돌시 아이템이 사라진다.
    {
        if(other.gameObject.tag == "water")
        {
            Destroy(gameObject);
        }else if(other.gameObject.tag == "item")
        {
            Destroy(gameObject);
        }
    }
}
