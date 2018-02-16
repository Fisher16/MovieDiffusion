    $(document).ready(function() {
 //MovieDB
    var top=[];
    top[2]={"overview":"Set in the Little Saigon district outside of Sydney, a woman trying to escape her past becomes embroiled in a drug deal.",
            "poster_path":"/zJhyMfoZBA6UUHTEYcoSAdNi2Gx.jpg",
            "title":"Little Fish"}
    top[1]={"overview":"While holidaying in the French Alps, a Swedish family deals with acts of cowardliness as an avalanche breaks out.",
            "poster_path":"/rGMtc9AtZsnWSSL5VnLaGvx1PI6.jpg",
            "title":"Force Majeure"}
    top[0]={"overview":"Former Danish servicemen Lars and Jimmy are thrown together while training in a neo-Nazi group. Moving from hostility through grudging admiration to friendship and finally passion, events take a darker turn when their illicit relationship is uncovered.",
            "poster_path":"/q19Q5BRZpMXoNCA4OYodVozfjUh.jpg",
            "title":"Brotherhood"}
      //#1
      var mdbPoster='<img src=\"https://image.tmdb.org/t/p/w342';

      $( ".title1" ).html( top[2]['title'] );
      if(top[2]['poster_path'])$( ".mdbImg1" ).html( mdbPoster+ top[2]['poster_path'] + '\">' );
      $( ".description1" ).html( top[2]['overview'] );

      $( ".title2" ).html( top[1]['title'] );
      if(top[1]['poster_path'])$( ".mdbImg2" ).html( mdbPoster+ top[1]['poster_path'] + '\">' );
      $( ".description2" ).html( top[1]['overview'] );

      $( ".title3" ).html( top[0]['title'] );
      if(top[0]['poster_path'])$( ".mdbImg3" ).html( mdbPoster+ top[0]['poster_path'] + '\">' );
      $( ".description3" ).html( top[0]['overview'] );

    });//docready
