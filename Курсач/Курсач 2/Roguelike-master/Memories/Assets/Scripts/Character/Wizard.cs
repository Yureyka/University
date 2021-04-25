﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Wizard : PlayerBase
{
    private GameObject projectile;
    public float projectileForce;
    public int numberBullet;
    public GameObject teleportFX;

    void Update ()
	{
		TakeInput ();
		Move ();
        Attack();
        SwapProjectile();
        Dash();
    }

    protected override void Attack()
    {
        if (Input.GetMouseButtonDown(0) && Time.timeScale == 1)
        { 
            if (!GameObject.FindGameObjectWithTag("GOManager")) return;
            projectile = GameObject.FindGameObjectWithTag("GOManager").GetComponent<GOManager>().bullet[numberBullet];
            Vector2 mousePos = UnityEngine.Camera.main.ScreenToWorldPoint(Input.mousePosition);
            Vector2 myPos = transform.position;
            Vector2 direction = (mousePos - myPos).normalized;
            GameObject spell = Instantiate(projectile, transform.position, Quaternion.identity);
            spell.GetComponent<Rigidbody2D>().velocity = direction * projectileForce;
            spell.GetComponent<Projectile>().damage = Random.Range(minDamage, maxDamage);
        }
    }

    void Dash()
    {
        if (Input.GetKeyDown(KeyCode.F))
        {
            Destroy(Instantiate(teleportFX, transform.position, Quaternion.identity), 1f);
            transform.Translate(direction * 1.75f);
        }  
    }

    void SwapProjectile()
    {
        //смена снарядов
    }
}