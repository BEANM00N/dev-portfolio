---
title: Shoot to Die
date: 2025-11-10
summary: An incremental Dice Shooting Game
tags:
  - Unreal Engine
  - Blueprints
  - Tech Art
status: published
draft: false
image:
  preview_only: true
---

<style>
  /* 1. Set the fixed, darkened background image for the whole page */
  body {
    background-image: linear-gradient(rgba(15, 23, 42, 0.45), rgba(15, 23, 42, 0.55)), url('featured.jpg') !important;
    background-size: cover !important;
    background-attachment: fixed !important;
    background-position: center !important;
  }

  /* 2. Wrap your content in a premium "glass" card like Tony's */
  article {
    background-color: rgba(30, 41, 59, 0.6) !important;
    backdrop-filter: blur(12px);
    -webkit-backdrop-filter: blur(12px);
    border: 1px solid rgba(255, 255, 255, 0.1);
    border-radius: 1.5rem;
    padding: 3rem;
    margin-top: 3rem;
    margin-bottom: 3rem;
  }

 /* 3. Custom Action Button */
  .custom-play-btn {
    display: inline-flex;
    align-items: center;
    gap: 0.6rem;
    padding: 0.6rem 1.25rem; /* Slightly adjusted padding for a perfect pill/rectangle */
    border: 2px solid #e05e5e; 
    border-radius: 0.5rem;
    color: white !important;
    text-decoration: none !important;
    font-weight: 600;
    font-size: 1.1rem;
    line-height: 1 !important; /* Keeps the text from stretching the button vertically */
    background-color: transparent;
    transition: all 0.2s ease-in-out;
    margin-bottom: 2rem;
  }
  
  .custom-play-btn:hover {
    background-color: #e05e5e; 
    color: white !important;
  }
  
  /* Forces the external SVG icon to size correctly */
  .custom-play-btn img {
    width: 1.25rem !important;
    height: 1.25rem !important;
    object-fit: contain;
    display: block;
    margin: 0 !important; /* This kills the giant default image margins! */
  }

 /* 4. Table of Contents - Tony's Fluid Sidebar (Updated for Tailwind) */
  .docs-toc, .toc, #TableOfContents, aside nav {
    background-color: rgba(30, 41, 59, 0.6) !important;
    backdrop-filter: blur(12px);
    -webkit-backdrop-filter: blur(12px);
    border-radius: 1rem;
    padding: 1.5rem !important;
    border-left: 4px solid #e05e5e !important; /* The solid red line on the left */
    margin-top: 3rem;
  }

  /* Style the "On this page" header */
  .docs-toc h2, .docs-toc h3, .toc h2, aside nav h2 {
    color: white !important;
    font-size: 1.1rem !important;
    margin-bottom: 1rem !important;
    font-weight: 600 !important;
  }

  /* Remove default bullet points */
  .docs-toc ul, .toc ul, #TableOfContents ul, aside nav ul {
    list-style: none !important;
    padding-left: 0 !important;
    margin: 0 !important;
  }
  
  /* Indent sub-headings slightly */
  .docs-toc ul ul, .toc ul ul, #TableOfContents ul ul, aside nav ul ul {
    padding-left: 1rem !important; 
  }

  /* Style the links */
  .docs-toc a, .toc a, #TableOfContents a, aside nav a {
    color: #94a3b8 !important; /* Muted grey text */
    text-decoration: none !important;
    display: inline-block;
    padding: 0.3rem 0.8rem;
    border-radius: 9999px !important; /* Pill shape */
    transition: all 0.2s ease-in-out;
    margin-bottom: 0.2rem;
    font-size: 0.9rem;
    border: 1px solid transparent !important; 
    width: 100%;
  }

  .docs-toc a:hover, .toc a:hover, #TableOfContents a:hover, aside nav a:hover {
    color: white !important;
    background-color: rgba(255, 255, 255, 0.05) !important;
  }

  /* The magic 'active' class applied by Hugo's Scrollspy */
  .docs-toc a.active, .toc a.active, #TableOfContents a.active, aside nav a.active {
    color: white !important;
    border: 1px solid #e05e5e !important; /* Tony's red pill outline */
    background-color: transparent !important;
  }
</style>

<a href="https://mad-moon-studios.itch.io/shoot-to-die" class="custom-play-btn" target="_blank">
  <img src="https://static.itch.io/images/itchio-textless-white.svg" alt="Itch.io logo">
  Play
</a>

## Gameplay Trailer
(Embed your trailer here later)

## Full Demo Gameplay
(Embed your demo here later)

## Overview
Shoot to Die is a fast-paced incremental game...

## Combat Design
We focused heavily on dice mechanics...