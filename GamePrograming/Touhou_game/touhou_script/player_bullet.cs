using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class player_bullet : MonoBehaviour
{
    //int a = 0;
    //public int B_speed = 10;
    [SerializeField] private int B_speed = 10;
    // Start is called before the first frame update
    void Start()
    {
        AudioSource sound = GetComponent<AudioSource>();
        sound.Play();
    }

    /*
    private void OnTriggerEnter2D(Collider2D collision)
    {
        //Debug.Log("B_hit!!!!!!");
        if (collision.tag == "enemy")
        {
            Destroy(gameObject);
        }
    }
    */

    // Update is called once per frame
    void Update()
    {
        //a++
        transform.Translate(Vector2.up * B_speed * Time.deltaTime, Space.Self);

        /*
        if(a > 200){
            Destroy(self);
        }
        */
        if (gameObject.transform.position.y >= 16)
        { // 거리 벌어지면 파괴
            Destroy(gameObject);
        }
    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("enemy"))
        {
            Destroy(gameObject);
        }
        
    }
    private void OnTriggerEnter2D(Collider2D collision){
        if (collision.gameObject.CompareTag("boss"))
        {
            Destroy(gameObject);
        }
    }
}
