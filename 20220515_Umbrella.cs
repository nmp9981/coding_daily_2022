using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UmbrellaMgr : MonoBehaviour
{
    PersonMov personMove;

    // Start is called before the first frame update
    void Start()
    {
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
}
