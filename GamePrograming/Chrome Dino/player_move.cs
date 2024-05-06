using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class player_move : MonoBehaviour
{
    private Rigidbody2D rb;
    private bool isJump = false;
    public bool Gameover = false;
    public float jumpPower = 10f;
    
    public int game_speed = 10;

    public GameObject gmo_obj;
    public GameObject re;

    public int pos_check = 0;

    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        gmo_obj.SetActive(false);
        re.SetActive(false);
    }

    void Update()
    {
        if (!Gameover) // 게임 오버가 아닐 때만 조작 가능
        {
            if (Input.GetKeyDown(KeyCode.Space) && !isJump)
            {
                isJump = true;
                Jump();
            }
            if (Input.GetKey(KeyCode.RightArrow)){
                game_speed = 15;
                pos_check = 1;
            }
            else if (Input.GetKey(KeyCode.LeftArrow)){
                game_speed = 5;
                pos_check = -1;
            }
            else{
                game_speed = 10;
                pos_check = 0;
            }
        }
        
        if(pos_check == 0){
            if(transform.position.x >= -6.5f){
                transform.position += new Vector3(-0.01f, 0f, 0f);
            }
            if(transform.position.x < -6.5f){
                transform.position += new Vector3(0.01f, 0f, 0f);
            }
        }
        if(pos_check == 1){
            if(transform.position.x <= -5.5f){
                transform.position += new Vector3(0.01f, 0f, 0f);
            }
        }
        if(pos_check == -1){
            if(transform.position.x >= -7.5f){
                transform.position += new Vector3(-0.01f, 0f, 0f);
            }
        }
    }

    void Jump()
    {
        if(pos_check == 0)
            rb.velocity = new Vector2(0, jumpPower);
        else if(pos_check == 1)
            rb.velocity = new Vector2(0, jumpPower+8);
        else if(pos_check == -1)
            rb.velocity = new Vector2(0, jumpPower-3);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Ground"))
        {
            isJump = false;
        }
        if (collision.gameObject.CompareTag("Gameover"))
        {
            Gameover = true;
            game_speed = 0;
            rb.constraints = RigidbodyConstraints2D.FreezeAll;
            gmo_obj.SetActive(true);
            re.SetActive(true);
        }
    }
}
