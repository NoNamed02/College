using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class boss_bullet_2 : MonoBehaviour
{
    private Vector3 playerDirection; // 플레이어 방향을 저장할 변수
    [SerializeField] private float speed1 = 1.0f;
    [SerializeField] private float speed2 = 8.0f;
    [SerializeField] private int timing = 0;

    private bool ro_check = false;

    private int time_check = 0;
    //private bool isMovingTowardsPlayer = false;

    // Update is called once per frame
    void Update()
    {
        GameObject playerObject = GameObject.FindGameObjectWithTag("Player");
        time_check++;

        if (time_check < 70)
        {
            // 500프레임 미만일 때, 아래로 이동
            transform.Translate(Vector3.down * Time.deltaTime * speed1);
        }
        else if (time_check < 200 && time_check >= 70)
        {
            // 500프레임 이상, 1000프레임 미만일 때, 플레이어를 향해 회전하고 멈춤
            if (playerObject != null)
            {
                playerDirection = (playerObject.transform.position - transform.position).normalized;
                RotateToFaceDirection(playerDirection); // 플레이어를 향해 회전
                //isMovingTowardsPlayer = true; // 플레이어를 향해 이동 중임을 표시
            }
            else
            {
                Destroy(gameObject); // 플레이어를 찾지 못한 경우 총알 파괴
            }
        }
        else
        {
            if(ro_check == false){
                if (playerObject != null)
                {
                    playerDirection = (playerObject.transform.position - transform.position).normalized;
                }
            }
            transform.Translate(Vector3.up * Time.deltaTime * speed2);
        }

        if (timing > 200)
        { // 거리 벌어지면 파괴
            Destroy(gameObject);
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Player"))
        {
            Destroy(gameObject);
        }
    }

    // 이동 방향에 따라 객체를 회전시키는 함수
    private void RotateToFaceDirection(Vector3 direction)
    {
        if (direction != Vector3.zero)
        {
            // 플레이어를 향하는 방향을 구하고, 그 방향으로 회전
            float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg - 90f;
            transform.rotation = Quaternion.AngleAxis(angle, Vector3.forward);

            // 이동 방향도 설정
            playerDirection = direction;
        }
    }
    private void OnTriggerEnter2D(Collider2D collision){
        if (collision.gameObject.CompareTag("spellcard"))
        {
            Destroy(gameObject);
        }
    }
}
