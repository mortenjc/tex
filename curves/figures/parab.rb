model    = Sketchup.active_model
entities = model.active_entities
materials= model.materials

def myz(x,y)
   return (x*x + y*y)/20.0
end

m1 = materials.add "my_mat_1"
m2 = materials.add "my_mat_2"
m1.color = "blue"
m2.color = "red"

def parab(x,y,v,entities)
  for i in -9...9
    for j in -9...9
      mx=(1.0*i)
      my=(1.0*j)
      p1= [x+mx  , y+my  , myz(mx  ,my  )/v ]
      p2= [x+mx+1, y+my  , myz(mx+1,my  )/v ]
      p3= [x+mx+1, y+my+1, myz(mx+1,my+1)/v ]
      p4= [x+mx  , y+my+1, myz(mx  ,my+1)/v ]

      f=entities.add_face(p1,p2,p3,p4)
      f.material="my_mat_2"
      f.back_material="my_mat_1"
    end
  end
end

parab( 0,  0, 0.5,entities)
parab(20,  0,   1,entities)
parab(40,  0,   2,entities)
parab(60,  0, 800,entities)
parab( 0, 20,-0.5,entities)
parab(20, 20,  -1,entities)
parab(40, 20,  -2,entities)
parab(60, 20,-800,entities)
